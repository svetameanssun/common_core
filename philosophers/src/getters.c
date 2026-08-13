/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:48:23 by stitovsk          #+#    #+#             */
/*   Updated: 2024/08/28 16:49:38 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_created(t_philo *philo)
{
	int	created_flg;

	pthread_mutex_lock(&philo->data->aux_lock);
	created_flg = philo->created;
	pthread_mutex_unlock(&philo->data->aux_lock);
	return (created_flg);
}

int	is_full(t_philo *philo)
{
	int	full;

	pthread_mutex_lock(&philo->data->meal_lock);
	full = philo->mls_eaten == philo->data->mls_to_eat;
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (full);
}

int	check_time(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->data->meal_lock);
	time = (get_current_time() - philo->last_meal)
		> (size_t)philo->data->time_to_die;
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (time);
}

int	smbd_dead(t_supper *data)
{
	int	dead_flag;

	pthread_mutex_lock(&data->dead_lock);
	dead_flag = data->dead_flg;
	pthread_mutex_unlock(&data->dead_lock);
	return (dead_flag);
}
