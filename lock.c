/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:52:40 by asyed             #+#    #+#             */
/*   Updated: 2018/02/25 01:35:48 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	void	*handle;
	void	(*func)(int, int, int, int);
	char	*name;

	if (!(name = calloc(1024, sizeof(char *))))
		return (-1);
	if (gethostname(name, 1024) == -1)
		return (-1);
	handle = dlopen("/System/Library/PrivateFrameworks/login.framework/Versions/A/login", RTLD_LAZY);
	if (!handle)
		return (-1);
	if (strstr(name, "42.us.org"))
		func = dlsym(handle, "SACLOStartLogout");
	else
		func = dlsym(handle, "SACSwitchToLoginWindow");
	if (!func)
		return (-1);
	func(1, 1, 0, 0);
}
