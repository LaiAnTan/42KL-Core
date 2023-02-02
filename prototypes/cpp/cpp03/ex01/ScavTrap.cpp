#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

ScavTrap::ScavTrap(void)
{
	cout << "ScavTrap: Default Constructor called" << endl;
}

ScavTrap::ScavTrap(string name): ClapTrap(name, 100, 50, 20)
{
	cout << "ScavTrap: Constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap)
{
	cout << "ScavTrap: Copy constructor called" << endl;
	*this = scavtrap;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scavtrap)
{
	cout << "ScavTrap: Copy assignment operator called" << endl;
	if (this == &scavtrap)
		return (*this);
	this->name = scavtrap.name;
	this->hitPoints = scavtrap.hitPoints;
	this->energyPoints = scavtrap.energyPoints;
	this->attackDamage = scavtrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap: Destructor called" << endl;
}

void	ScavTrap::attack(const string &target) 
{
	energyPoints -= 1;
	cout << "ScavTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
}

void	ScavTrap::guardGate(void)
{
	cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << endl;
}