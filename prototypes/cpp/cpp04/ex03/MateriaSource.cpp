#include "MateriaSource.hpp"

#include <iostream>

using std::cout;
using std::endl;

MateriaSource::MateriaSource()
{
	cout << "MateriaSource: Constructor called" << endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource)
{
	cout << "MateriaSoucre: Copy constructor called" << endl;
	*this = materiasource;

}

MateriaSource &MateriaSource::operator = (const MateriaSource &materiasource)
{
	cout << "MateriaSource: Copy assignment operator called" << endl;
	if (this == &materiasource)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->mem[i] = materiasource.mem[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	cout << "MateriaSouce: Destructor called" << endl;
}

void MateriaSource::learnMateria(AMateria* type)
{
	int	i = -1;

	while(++i < 4)
	{
		if (this->mem[i] != 0)
			continue;
		this->mem[i] = type;
		return ;
	}
	cout << "MateriaSource: No space left in memory" << endl;
}

AMateria* MateriaSource::createMateria(string const & type)
{
	int i = -1;

	while (++i < 4)
	{
		if (type.compare(mem[i]->getType()) == 0)
			return (mem[i]->clone());
	}
	return (NULL);
}
