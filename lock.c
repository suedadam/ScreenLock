/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:52:40 by asyed             #+#    #+#             */
/*   Updated: 2018/02/25 00:12:30 by asyed            ###   ########.fr       */
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
	void	(*func)(void);
	char	*name;

	if (!(name = calloc(1024, sizeof(char *))))
		return (-1);
	if (gethostname(name, 1024) == -1)
		return (-1);
	if (strstr(name, "42.us.org"))
		return (-1);
	free(name);
	name = NULL;
	handle = dlopen("/System/Library/CoreServices/Menu Extras/User.menu/Contents/MacOS/User", RTLD_LAZY);
	if (!handle)
		return (-1);
	func = dlsym(handle, "SACSwitchToLoginWindow");
	if (!func)
		return (-1);
	func();
}
