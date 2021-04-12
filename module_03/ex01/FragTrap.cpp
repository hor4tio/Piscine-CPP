/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:29:31 by allanganoun       #+#    #+#             */
/*   Updated: 2021/04/12 19:45:36 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
:hp(100), max_hp(100), energy(100), max_energy(100), lvl(1), melee(30), ranged(20), armor_red(5)
{
	this->name = "John Doe";
	this->attack_name = "None";
}

FragTrap::FragTrap(std::string name)
:hp(100), max_hp(100), energy(100), max_energy(100), lvl(1), melee(30), ranged(20), armor_red(5)
{
	this->name = name;
	this->attack_name = "None";
	std::cout << this->name + " appears." << std::endl;
}

FragTrap::~FragTrap()
{
	if (this->hp == 0)
		std::cout << this->name + "'s corpse vanishes..." << std::endl;
	else
		std::cout << this->name + " vanishes..." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->energy = rhs.getEnergy();
	return (*this);
}

int		FragTrap::getEnergy() const
{
	return (this->energy);
}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "[RANGED] " + this->name + " uses " +
		this->attack_name + " on " + target +
		" causing " << this->ranged << " points of damages" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "[MELEE] " + this->name + " uses " +
		this->attack_name + " on " + target +
		" causing " << this->melee<< " points of damages" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	this->hp -= (amount - this->armor_red);
	if (this->hp < 0)
		this->hp = 0;
	std::cout << this->name + " HPs are now " << this->hp << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (hp == 0)
		std::cout << this->name + " is already dead, he can't be healed." << std::endl;
	else
	{
		this->hp += amount;
		if (this->hp > 100)
			this->hp = 100;
		std::cout << this->name + " healed "<< amount << " and is now " << this->hp << std::endl;
	}
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attack_list[6] = {"Normal attack", "Medium attack", "Heavy attack", "Normal ranged attack", "Medium ranged", "Heavy ranged attack"};
	if (this->energy > 0)
		this->energy -= 25;
	static int random = 0;
	srand (time(0) + random++);
	int i = rand() % 6;
	if (this->energy != 0 && this->hp != 0)
	{
		this->attack_name = attack_list[i];
		if (i < 5)
			this->meleeAttack(target);
		else
			this->rangedAttack(target);
	}
	else if (this->energy == 0)
		std::cout << this->name + " cant attack without energy." << std::endl;
	else if (this->hp == 0)
		std::cout << this->name + " is dead, he can't attack anymore." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, FragTrap const &temp)
{
	out << temp.getEnergy();
	return (out);
}
