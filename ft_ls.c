/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperret <tperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:14:32 by tperret           #+#    #+#             */
/*   Updated: 2014/12/01 09:48:50 by tperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../Git_Vogsphere/libft.h"
int main(int argc, char **argv)
{
	char	*Cmd = NULL;
	int		statut;

	if ( argc != 2 )
	{
		fprintf (stderr, 
		" Pas le bon nombre d'arguments.. Usage : %s repertoire",argv[0]);
		return ( 1 );
	}
	Cmd = malloc ( (strlen (argv[1])+1) + 20 );
	if ( Cmd == NULL )
	{
		fprintf ( stderr, " Erreur d'allocation mémore");
		return (1);
	}
	sprintf ( Cmd,  "ls -l %s | wc -w", argv[1] );

	statut = system(Cmd) ;
	free(Cmd);
	Cmd = NULL ;
	return statut ;
}
