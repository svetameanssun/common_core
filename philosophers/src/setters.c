/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:42:16 by stitovsk          #+#    #+#             */
/*   Updated: 2024/08/28 17:09:39 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_created_flag(t_philo *philo, t_supper *data)
{
	pthread_mutex_lock(&data->aux_lock);
	philo->created = 1;
	pthread_mutex_unlock(&data->aux_lock);
}

void	add_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->mls_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
}

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->meal_lock);
}

void	set_dead_flag(t_supper *data, int dead_flag)
{
	pthread_mutex_lock(&data->dead_lock);
	data->dead_flg = dead_flag;
	pthread_mutex_unlock(&data->dead_lock);
}
