/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:30:04 by allanganoun       #+#    #+#             */
/*   Updated: 2021/04/10 19:51:11 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <unistd.h>
class FragTrap
{
private:
	int			hp;
	int			max_hp;
	int			energy;
	int			max_energy;
	int			lvl;
	int			melee;
	int			ranged;
	int			armor_red;

	std::string	name;
	std::string	attack_name;
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	int		getCurrent();
	int		getEnergy();
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};


#endif