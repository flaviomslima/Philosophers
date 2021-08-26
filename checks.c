/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 19:57:02 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->n_eat == state.eat_rep)
	{
		printf("[%d]\t %d\t is satisfied\n", current, philo->position);
		state.all_satisfated--;
	}
	if (state.all_satisfated == 0)
		exit(0);
}

void	check_die(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->last_eat + state.t_die < current)
	{
		printf("[%d]\t %d\t is die\n", current, philo->position);
		exit (0);
	}
}
