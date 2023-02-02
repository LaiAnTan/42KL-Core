#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

using	std::string;

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(string name);
		DiamondTrap(const DiamondTrap &diamondtrap);
		DiamondTrap &operator = (const DiamondTrap &diamondtrap);
		~DiamondTrap();

		using	FragTrap::hitPoints;
		using	ScavTrap::energyPoints;
		using	FragTrap::attackDamage;
		using	ScavTrap::attack;

	private:
		string name;
};

#endif