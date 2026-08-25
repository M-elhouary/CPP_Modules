# 🧠 CPP Module 08 — Full Explanation Guide

> **Templated containers, iterators, algorithms**
> A complete walkthrough to explain the module to a peer: concepts, code, reasoning, and internals.

---

## 📚 Table of Contents

- [Module Overview](#-module-overview)
- [Simple Explanations First](#-simple-explanations-first)
- [The Toolbox (concepts used everywhere)](#%EF%B8%8F-the-toolbox)
- [Exercise 00 — easyfind](#-exercise-00--easyfind)
- [Exercise 01 — Span](#-exercise-01--span)
- [Exercise 02 — MutantStack](#-exercise-02--mutantstack)
- [Cheat Sheet](#-cheat-sheet)

---

# 🌍 Module Overview

This module is **the introduction to the STL** (Standard Template Library).
Until now, containers and algorithms were forbidden. Here they become the whole point.

| Rule | Meaning |
|---|---|
| Compiler | `c++` with `-Wall -Wextra -Werror` |
| Standard | **C++98 only** (no `auto`, no lambdas, no `nullptr`) |
| Forbidden | `*printf`, `*alloc`, `free`, `using namespace`, `friend` |
| Design | Every class in **Orthodox Canonical Form** (OCF) |
| Headers | No function implementation in headers **except templates** |

**OCF reminder** — every class must provide:

```cpp
ClassName();                                // default constructor
ClassName(const ClassName &src);            // copy constructor
~ClassName();                               // destructor
ClassName &operator=(const ClassName &rhs); // copy assignment operator
```

---

# 🧸 Simple Explanations First

Plain-language versions before diving deep. If you can explain these five words,
the whole module becomes easy.

## What is a **container**? 📦

> A box that holds many values of the same type and manages them for you.

```cpp
std::vector<int> v;   // a box of ints, grows automatically
v.push_back(5);       // put 5 in the box
```

You never ask "how much memory do I need?" like in C — the box resizes itself.
Different boxes have different superpowers: `vector` (fast access),
`list` (fast insert), `stack` (top-only)…

## What is an **iterator**? 👉

> A finger pointing at one element inside the box. You can move it and read what it points at.

```text
box:    [ 9 ][ 4 ][ 4 ][ 7 ]
         ↑
        it          ← your finger points here
*it → 9            read through the finger
++it               move finger right
it != end()        "is my finger past the last element?"
```

Think: *pointer's well-behaved cousin.* Every container has its own finger type,
but they all speak the same language (`*`, `++`, `!=`, `==`).
That's why ONE algorithm like `std::find` works on EVERY box.

```cpp
std::vector<int>::iterator it1 = v.begin();  // finger on first element
std::list<int>::iterator  it2 = l.begin();   // different finger type, same usage
```

## What are **begin() / end()**? 🚩

> `begin()` = finger on the FIRST element.
> `end()` = finger on the position AFTER the last element (a flag, not a real value).

```text
[ 9 ][ 4 ][ 7 ] ✕
  ↑           ↑
begin()     end()   ← dereferencing end() is FORBIDDEN (nothing there)
```

Why this weird convention? It makes loops clean:

- loop while `it != end()` → stops exactly after the last element
- empty box? then `begin() == end()` immediately — zero special cases
- `end()` doubles as the answer to "not found" in searches

## What is a **template**? 🍪

> A cookie cutter. You write the shape ONCE; the compiler stamps out real code for each dough you press it into.

```cpp
template<typename T>
T biggest(T a, T b) { return a > b ? a : b; }

biggest(3, 7);        // compiler makes: int      biggest(int, int)
biggest(2.5, 1.5);    // compiler makes: double   biggest(double, double)
```

You wrote one function; the compiler wrote two. No copy-paste, works for any type.
That's all our exercises do:

| Code | The "dough" pressed in |
|---|---|
| `easyfind(list, 6)` | T = `std::list<int>` |
| `addRange(v.begin(), v.end())` | Iterator = vector's finger |
| `MutantStack<int>` | T = `int` |

**Rule that follows:** the cutter must be visible where cookies are stamped →
template code lives in headers (`.hpp` / `.tpp`).

## What is **container_type**? 🎁

> A nickname a container gives to its own inner parts, so you can write generic code without knowing them.

`std::stack` secretly wraps another box (a deque). Instead of hardcoding
"deque", it publishes the name:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
//                └── "whatever box is inside you" ──┘
```

Reads as: *"take the iterator-finger of whatever container hides inside the stack,
and give it the nickname `iterator`."*
If tomorrow stack wraps a list instead of a deque, the typedef still works —
zero changes needed. That's the power of asking containers to describe themselves.

## One sentence each 📝

| Word | In one sentence |
|---|---|
| **container** | a self-managing box of values |
| **iterator** | a movable finger pointing at one element |
| **begin()/end()** | fingers on first element / just-past-the-last flag |
| **template** | a cookie cutter the compiler stamps per type |
| **typename** | tells the compiler "this dependent name is a TYPE" |
| **container_type** | a container publishing nicknames for its inner types |

---
---

# 🧰 The Toolbox

Concepts shared by all three exercises. Master these first.

## 1. Templates = blueprints, not code

```cpp
template<typename T>
typename T::iterator easyfind(T &container, int n);
```

Writing this creates **nothing**. Only when a call happens does the compiler
**deduce** `T` and stamp out a concrete function:

```cpp
easyfind(list, 6);    // compiler writes a version for std::list<int>
easyfind(vec, 6);     // ...and another one for std::vector<int>
```

### Why templates must live in headers

Normal split: `.cpp` compiled → object file with symbols → linker connects calls.
With templates, `.cpp` alone knows no type ⇒ **no symbol is ever generated**
⇒ caller hits `undefined reference`.
Fix: definition must be visible where the call happens → **header** (or `.tpp` included by it).
That's why the rule *"no implementation in headers"* has the exception: **except templates**.

### The `typename` keyword

```cpp
typename T::iterator   // ← why 'typename'?
```

Templates are parsed in two passes. Before `T` is known, `T::iterator`
could be a type, a variable, or a function. By default the parser assumes
**value**. `typename` forces "**treat me as a type**".
Without it: compile error.

## 2. Iterators and the `[begin, end)` range

Every container exposes two positions:

```text
list:   [9] [4] [4] [7] ?
         ^           ^
      begin()      end()   ← NOT the last element!
                             it's "one past the end" (a sentinel)
```

| Call | Returns |
|---|---|
| `begin()` | iterator to the **first** element |
| `end()` | iterator **just after the last** element (never dereference it!) |

Together they form the half-open range `[begin, end)` — "from first up to,
but not including, end". An empty container simply satisfies `begin() == end()`.

This convention makes loops uniform for every container shape:

```cpp
while (it != end())
{
    // use *it
    ++it;
}
```

## 3. `std::vector` vs `std::list`

```text
vector : ┌────┬────┬────┬────┐   one contiguous memory block
         │ 9  │ 4  │ 4  │ 7  │
         └────┴────┴────┴────┘

list   : [prev|9|next]→[prev|4|next]→[prev|7|next]
           separate nodes linked by pointers
```

| Operation | `vector` | `list` | Reason |
|---|---|---|---|
| Access i-th (`v[i]`) | **O(1)** | O(n) | address arithmetic vs walking links |
| Insert / erase middle-front | O(n) shift | **O(1)** rewire | shifting vs relinking |
| Iteration speed | **fast** | slower | cache locality |
| Memory per element | just `T` | `T` + 2 pointers | node overhead |
| Iterator type | random-access (`it + n` OK) | bidirectional (`++`/`--` only) | layout |

**Consequence seen in Span:** `std::sort(v.begin(), v.end())` compiles,
`std::sort(l.begin(), l.end())` does not — sort needs random-access iterators;
a list offers its own slower member `l.sort()` instead.

**Rule of thumb:** default to `vector`; pick `list` only for cheap mid-sequence
splicing or stable iterators.

---
---

# 🔍 Exercise 00 — easyfind

| | |
|---|---|
| **Goal** | find an `int` inside any integer container |
| **Files** | `Makefile`, `main.cpp`, `easyfind.hpp` |

## The concept

Write **one generic function** that searches any STL sequence container,
delegating the search to the standard algorithm `std::find`.

## The code — annotated

```cpp
template<typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("not found");
	return it;
}
```

| Line | What it does | Why |
|---|---|---|
| `template<typename T>` | blueprint over any container | one source, many instantiations |
| `typename T::iterator` (return) | returns *the position*, not the value | callers may continue from there; matches STL style (`std::find` behaves the same) |
| `typename` keyword | forces "type" interpretation | dependent name parsing rule |
| `std::find(begin, end, n)` | the actual search | required: must use **STL algorithms**, not hand loops |
| `it == container.end()` | failure test | `end()` is the universal "not found" signal |
| `throw` | report failure | standard containers have no null iterator; exceptions are the idiomatic channel |

## How `std::find` works internally

```cpp
template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first)
        if (*first == value)
            return first;    // first occurrence wins
    return last;             // reached sentinel → not found
}
```

Example on `{9, 4, 4, 7}` searching `4`: stops at index 1 → `*it == 4`.
Searching `100`: walks to `end()` → throws.

Because it only uses `!=`, `++`, `*`, the same algorithm serves vector
(contiguous), list (linked), deque… **iterators abstract storage away**.

## Why `*easyfind(list, 6)`?

`easyfind` returns an **iterator**, and `*` dereferences it into the stored
value — exactly like a pointer:

```cpp
std::cout << *easyfind(list, 6);                  // direct deref
std::list<int>::iterator it = easyfind(list, 6);  // or store first…
std::cout << *it;                                 // …if reused later
```

No intermediate pointer is needed — `*expr` works on any expression
yielding an iterator or pointer.

## Exception design: `runtime_error` vs a custom class

Current choice:

```cpp
throw std::runtime_error("not found");
```

Alternative (more professional API):

```cpp
class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw() { return "element not found"; }
};
```

| Approach | Pro | Con |
|---|---|---|
| `runtime_error` | zero boilerplate, message included | catchable only as generic error |
| custom class | catch **by type**: `catch (NotFoundException &)` before `catch (std::exception &)` | more code; order matters (derived first!) |

Both accepted; the second shows design intent.

## Tests shipped (main.cpp)

- `std::list` filled 0–9 → find `6` ✅ prints `6`
- find `11` ❌ caught → prints `not found` (stderr)
- same pair of cases on a `std::vector`

Covers both containers × both outcomes — enough to prove behavior.

---
---

# 📏 Exercise 01 — Span

| | |
|---|---|
| **Goal** | a class storing up to N ints, able to answer shortest/longest gaps fast |
| **Files** | `Makefile`, `main.cpp`, `Span.hpp`, `Span.cpp` |

## The concept

`Span sp(N)` stores at most N integers.

| Member | Behavior |
|---|---|
| `addNumber(int)` | adds one number; **throws** if already N stored |
| `shortestSpan()` | smallest distance between any two numbers; **throws** if `< 2` stored |
| `longestSpan()` | largest distance (= max − min); **throws** if `< 2` stored |
| `addRange(first, last)` *(bonus)* | fills from an iterator range in **one call** |

Subject example — sorted `{3, 6, 9, 11, 17}`:

```text
shortest = min neighbor gap = 11 − 9 = 2
longest  = 17 − 3           = 14
```

⚠️ **Trap:** shortest span ≠ difference of the two smallest values
(`6−3=3` would be wrong here). Neighbors after sorting decide.

## Class layout

```cpp
class Span
{
private:
	std::vector<int> _v;    // storage
	unsigned int _n;        // capacity

public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	Span &operator=(Span const &rhs);   // ← full OCF set
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
	template <typename Iterator>
	void addRange(Iterator first, Iterator last);   // template → header
};
```

### Why `std::vector` for storage?

1. **Algorithms demand random-access iterators** — `std::sort` needs them; a list can't comply directly.
2. **Contiguous memory** = cache-friendly scans/sorts at 100k+ elements.
3. Matches the subject hint about range-based insertion.
4. Copy/deep-copy handled internally → OCF trivial.

Rejected alternatives: `list` (no random access), raw arrays (manual leaks),
`map/set` (auto-sorting waste + duplicates silently dropped → wrong shortest span!).

### OCF notes

Copy ctor delegates via `*this = src`; assignment copies `_n` and `_v`
(vector deep-copies itself) behind a self-assignment check.

## `shortestSpan()` — the elegant pipeline

```cpp
int Span::shortestSpan() const
{
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
	std::vector<int> tmp(_v);                       // ① copy (method is const!)
	std::sort(tmp.begin(), tmp.end());              // ② sort        O(n log n)
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());  // ③ gaps
	return *std::min_element(tmp.begin() + 1, tmp.end());           // ④ min gap
}
```

After sorting, the closest pair must be **neighbors** ⇒ one linear pass suffices.

### Step-by-step on `{3, 6, 9, 11, 17}`

`std::adjacent_difference(first, last, out)` writes
`out[0] = copy`, then `out[i] = input[i] − input[i−1]`:

| step | reads | writes | array state |
|---|---|---|---|
| start | `3` | copy `3` | `{3, _, _, _, _}` |
| 1 | `6 − 3` | `3` | `{3, 3, _, _, _}` |
| 2 | `9 − 6` | `3` | `{3, 3, 3, _, _}` |
| 3 | `11 − 9` | `2` | `{3, 3, 3, 2, _}` |
| 4 | `17 − 11` | `6` | `{3, 3, 3, 2, 6}` |

In-place is legal: each cell is read once, saved in `prev`, *then* overwritten.

### Why `tmp.begin() + 1`?

Position 0 holds a **copy of the original first value — not a gap**:

```text
{3, 6, 9, 11, 17}  →adjacent_difference→  {3, 3, 3, 2, 6}
                                            ↑ fake header cell
```

Killer counter-example without `+ 1`:

```text
sorted {1, 100} → gaps array {1, 99}
min_element(begin(),     end())  → 1   ← WRONG (that's the copied 1)
min_element(begin()+1,   end())  → 99  ← correct
```

`min_element` cannot know which cells are meaningful — the offset is how
the caller says *"skip the header"*.

## `longestSpan()`

```cpp
return *std::max_element(_v.begin(), _v.end())
     - *std::min_element(_v.begin(), _v.end());
```

Largest gap is always global-max minus global-min — sorting unnecessary. O(n).

## `addRange()` — the improved fill (template)

```cpp
template <typename Iterator>
void addRange(Iterator first, Iterator last)
{
	if (static_cast<unsigned int>(std::distance(first, last)) > _n - _v.size())
		throw std::runtime_error("Span is full");
	while (first != last)
	{
		addNumber(*first);
		++first;
	}
}
```

### Anatomy of the guard

```cpp
std::distance(first, last)   // how many we WANT to add
_n - _v.size()               // how many slots REMAIN
```

- `distance` is O(1) on vector/pointer iterators, O(n) walk on list iterators.
- `_n - _v.size()` unsigned subtraction is safe: invariant `_v.size() <= _n` always holds.
- **`static_cast<unsigned int>`**: `distance` returns signed `ptrdiff_t`;
  comparing signed vs unsigned triggers `-Wsign-compare` → `-Werror` kills the build.
  The cast isn't cosmetic — removing it breaks compilation.

### Why validate BEFORE inserting? (strong exception guarantee)

Naive alternative — loop and let `addNumber` throw midway:

```text
capacity 5, range of 10 → inserts 5, THEN throws → span left half-filled 😱
```

With the pre-check: **all-or-nothing**. Either the whole range fits, or the
span stays untouched — like a database transaction.

### Why take iterators, not a container?

```cpp
sp.addRange(v.begin(), v.end());       // vector
sp.addRange(l.begin(), l.end());       // list
int arr[3]; sp.addRange(arr, arr + 3); // raw pointers work too!
sp.addRange(v.begin(), v.begin() + 2000); // partial ranges
```

Iterators are the STL's universal currency — minimal requirements
(`*first`, `++first`, `!=`) give maximal generality.

## ⚡ Why the subject demands ≥10,000 numbers

Measured benchmark (same data, same answers, `-O2`):

```text
      n |   naive O(n^2) |   sort O(n log n)
--------|----------------|------------------
   1000 |       0.000s   |     0.0000s
  10000 |       0.020s   |     0.0003s   ← subject minimum
  50000 |       0.477s   |     0.0019s
 100000 |       1.925s   |     0.0039s
1000000 |   too slow!!   |     0.0454s   (naive est. ~minutes)
```

Each ×10 size multiplies naive cost by ~100 (n²), sorting by only ~12 (n log n).
A naive all-pairs `shortestSpan` survives 5 numbers but chokes at scale —
the volume requirement is a **design test in disguise**.
Our pipeline answers 1M numbers in 45 ms.

## Tests shipped (main.cpp)

1. Subject example → prints exactly `2` / `14`
2. Exceptions: 1 element, empty span, overflowing single adds
3. Big span: 12 000 randoms + 2 000 partial range + list range (14 002 total),
   extreme values near INT_MAX, then overflow attempt

External edge-cases verified during review: real range overflow throws,
empty range accepted, duplicates → shortest `0`, negatives, self-assignment.

---
---

# 🧬 Exercise 02 — MutantStack

| | |
|---|---|
| **Goal** | make `std::stack` iterable without rewriting it |
| **Files** | `Makefile`, `main.cpp`, `MutantStack.hpp` |

## The concept

`std::stack` is a **container adaptor**: it stores nothing itself, it wraps
another container (default `std::deque`) exposing only:

```text
push()  pop()  top()  size()
          ↑ top-only access, no iteration possible
```

Fix: inherit from it and **drill a window** into what it already holds.

## The key fact that makes everything work

`std::stack` keeps its underlying container in a **protected** member named
`c` — mandated by the standard, protected precisely so derived classes
can access it:

```cpp
this->c   // the hidden deque<T> inside every stack
```

## The code — annotated

```cpp
template<typename T>
class MutantStack : public std::stack<T>   // public inheritance
{
public:
	MutantStack() {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	~MutantStack() {}

	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end()   { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end()   const { return this->c.end(); }
};
```

### Inheritance gives everything for free

Publicly inheriting `std::stack<T>` re-exports `push/pop/top/size/empty`
and operators — *"offers all its member functions"* costs zero lines.

### OCF through the base

| Member | Mechanism |
|---|---|
| default ctor | base ctor builds the inner deque |
| copy ctor | init-list forwards → base deep-copies all elements |
| dtor | base dtor destroys container — leak impossible |
| `operator=` | see below 👇 |

### Deep dive: the assignment operator

```cpp
MutantStack &operator=(MutantStack const &rhs)
{
	if (this != &rhs)                    // ② self-assignment guard
		std::stack<T>::operator=(rhs);   // ③ qualified BASE call
	return *this;                        // ④ enables chaining
}
```

1. **Signature** — return `MutantStack&` so `a = b = c` chains;
   `const &` parameter: no source copy, source never modified; `rhs` = right-hand side.
2. **Self-assignment guard** (`ms = ms`): compares addresses. Harmless here
   (base handles it), but vital habit — classes managing raw resources
   would free their own buffer then read freed memory without it.
3. **Why fully qualify?** Unqualified `operator=(rhs)` inside the body
   resolves to **this very function** → infinite recursion → stack overflow.
   `std::stack<T>::` targets the base version, which copies the inner `c`
   element-wise.
4. **`return *this`** — dereference the `this` pointer, hand back the object.

*(Footnote: the compiler-generated version would behave identically — writing
it explicitly demonstrates OCF mastery and future-proofs the class.)*

### The typedefs

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

- `container_type` — stack re-exports its wrapped container's type.
- `typename` — dependent-name rule again.
- Naming them `iterator`/`const_iterator` makes the subject's syntax work…

```cpp
MutantStack<int>::iterator it = mstack.begin();
```

…and satisfies STL conventions, so `std::find`, `std::max_element`,
range-constructors accept our iterators instantly.

### The four accessors

```cpp
iterator begin() { return this->c.begin(); }
```

**Why `this->c` and not `c`?** Two-phase lookup: bases depending on a
template parameter are excluded from ordinary lookup (a specialization
could theoretically lack `c`). Qualifying via `this->` defers resolution
to instantiation time. GCC error otherwise:
*"there are no arguments to 'c' that depend on a template parameter"*.

Iteration order = **bottom → top** = insertion order — matching `std::list`
with `push_back`. That's the proof the subject demands.

**Const overloads:** on a `const MutantStack&` only const members are callable;
returning `const_iterator` preserves immutability while allowing traversal.

### Zero new data members

Copying, slicing, lifetimes behave exactly like plain stack. The abomination
is three real functions wearing a trench coat. 🕵️

## Verification: MutantStack vs std::list

Same operations, both outputs **byte-identical** (verified with `diff`):

```text
MutantStack            std::list
17  ← top()/back()     17
1   ← size()           1
5                      5     ← iteration bottom→top
3                      3
5                      5
737                    737
0                      0
```

## Extra tests beyond the subject

- copy & assignment independence (`b(a)`, `c = a`)
- algorithms on iterators: `find`, `min_element`, `max_element`, `reverse`
- const iteration path
- another type: `MutantStack<std::string>`

---
---

# 🎯 Cheat Sheet

| Concept | One-liner |
|---|---|
| Template | blueprint; compiler stamps real functions per type at call sites |
| Templates in headers | mandatory visibility — instantiation happens in user's TU |
| `typename` | forces dependent-name to parse as a type |
| `[begin, end)` | half-open range; `end()` = sentinel = "not found" signal |
| `std::find` | walks `!=`/`++`/`*` → works on any container |
| `vector` vs `list` | contiguous+random-access vs linked+cheap-splice |
| `sort` requirement | needs random-access iterators → vector yes, list no |
| shortestSpan trick | sort → neighbors hold closest pair → scan gaps |
| `adjacent_difference` | `[copy][gap][gap]…` → consumers offset by `+1` |
| `longestSpan` shortcut | always `max − min` |
| Range-fill guard | pre-validate capacity → all-or-nothing (strong guarantee) |
| signed/unsigned compare | cast `std::distance` result or `-Werror` fires |
| MutantStack magic | inherit stack + expose protected member `c`'s iterators |
| `this->c` | dependent-base name needs qualification in templates |
| Qualified base call | `Base::operator=` avoids infinite recursion |
| Self-assign guard | compare `this != &rhs` — cheap insurance, OCF convention |

---

*Generated from the cpp08 evaluation walkthrough — compile-tested, valgrind-clean,
outputs diff-verified.* ✅
