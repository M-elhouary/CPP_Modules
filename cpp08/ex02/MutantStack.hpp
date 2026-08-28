
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
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

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
		const_iterator begin() const
		{
			return this->c.begin();
		}
		const_iterator end() const
		{
			return this->c.end();
		}
};

#endif
