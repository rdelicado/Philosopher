/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:23:04 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/13 13:50:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

// Definiciones de colores
# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"

/* structuras */

typedef struct s_philo	t_philo;

typedef struct s_table
{
	sem_t				control;
	pid_t				*child_pids;
	pid_t				pid;
	long				time_init;
	long				time_curr;
	int					is_dead;
	int					die_to_time;
	int					eat_to_time;
	int					sleep_to_time;
	int					thing_to_time;
	int					num_meals;
	int					cont_eat;
	int					n_philo;
}						t_table;

typedef struct s_philo
{
	t_table				*t;
	long				last_eat;
	long				time_init;
	int					index;
	int					meals;
	int					pid;
}						t_philo;

/* leaks.c */
void					leaks(void);
void					init_data_table(t_table *t);
void					init_data_philos(t_philo *p, t_table *t);
int						ft_strcmp(const char *s1, const char *s2);

/* philo.c */
void					checker_argv(t_table *t, char **av);
void					init_args(t_table *t, char **av);
long					time_start_prog(void);
int						main(int ac, char **av);


/* utils_philo.c */
void					ft_error_help(char *str);
void					ft_error(char *str);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
long					ft_usleep(int time);

/* create_processes.c */
void					set_philos(t_table *t, t_philo *p);
void					routine_philos(t_philo *p);
void					printf_action(t_philo *p, char *str);
void					routine_table(t_table *t);
void					init_semaphores(t_table *t);

/* utils_simulator.c */


/* utils_rutine */


#endif