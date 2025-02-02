#include "MutantStack.hpp"

#include <iterator>
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	std::cout << "Iterating" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<int>	s2(mstack);

	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		cout << *i << endl;
	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		*i = 1;
	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		cout << *i << endl;

	return 0;
}
