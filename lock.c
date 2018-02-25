/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:52:40 by asyed             #+#    #+#             */
/*   Updated: 2018/02/24 20:54:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>

int	main(void)
{
	void	*handle;
	void	(*func)(void);

	handle = dlopen("/System/Library/CoreServices/Menu Extras/User.menu/Contents/MacOS/User", RTLD_LAZY);
	if (!handle)
		return (-1);
	func = dlsym(handle, "SACSwitchToLoginWindow");
	if (!func)
		return (-1);
	func();
}
