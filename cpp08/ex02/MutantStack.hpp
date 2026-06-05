
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const &src) { *this = src; }
		~MutantStack() {}

		MutantStack &operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};

#endif
