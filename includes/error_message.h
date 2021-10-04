/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:05:47 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:05:48 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_OPEN_FILE		"Failed to open file.\nExit.\n"

# define ERR_READ_MAP		"Error occurred while reading map.\nExit.\n"
# define ERR_EMPTY_MAP		"No data found.\nExit.\n"
# define ERR_INCORRECT_MAP	"Incorrect map.\nExit.\n"
# define ERR_USAGE			"Usage : ./fdf <filename>\n"
# define ERR_MALLOC			"Malloc failed.\nExit\n"
# define ERR_MLX_INIT		"Failed to set up the connection to the \
graphical system.\nExit.\n"
# define ERR_NEW_WIN		"Failed to create a new window.\nExit.\n"
# define ERR_NEW_IMG		"Failed to create a new image.\nExit.\n"
# define ERR_GET_ADR		"Failed to get data address.\nExit.\n"

#endif
