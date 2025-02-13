/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:11:09 by mschippe          #+#    #+#             */
/*   Updated: 2025/02/13 18:58:07 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**getargs(int argc, char **argv)
{
	char	**args;
	int		index;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = malloc((argc + 1) * sizeof(char *));
		if (!args)
			return (NULL);
		index = 0;
		args[argc] = NULL;
		while (index < argc - 1)
		{
			args[index] = ft_strdup(argv[index + 1]);
			if (!args[index])
				return (fa((void **)args), NULL);
			index++;
		}
	}
	return (args);
}
