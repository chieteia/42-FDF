/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:01 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:06:01 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__
#  define MOUSE_SCROLL_UP	4
#  define MOUSE_SCROLL_DOWN	5
#  define ARROW_LEFT		123
#  define ARROW_RIGHT		124
#  define ARROW_DOWN		125
#  define ARROW_UP			126
#  define BUTTON_PLUS		41
#  define BUTTON_MINUS		27
#  define BUTTON_LESS		43
#  define BUTTON_MORE		47
#  define BUTTON_ESC		53
#  define BUTTON_1			18
#  define BUTTON_2			19
#  define BUTTON_3			20
#  define BUTTON_7			26
#  define BUTTON_8			28
#  define BUTTON_9			25
#  define BUTTON_I			34
#  define BUTTON_P			35
# endif

# ifdef __linux__
#  define MOUSE_SCROLL_UP	4
#  define MOUSE_SCROLL_DOWN	5
#  define ARROW_LEFT		65361
#  define ARROW_RIGHT		65363
#  define ARROW_DOWN		65364
#  define ARROW_UP			65362
#  define BUTTON_PLUS		59
#  define BUTTON_MINUS		45
#  define BUTTON_LESS		44
#  define BUTTON_MORE		46
#  define BUTTON_ESC		65307
#  define BUTTON_1			49
#  define BUTTON_2			50
#  define BUTTON_3			51
#  define BUTTON_7			55
#  define BUTTON_8			56
#  define BUTTON_9			57
#  define BUTTON_I			105
#  define BUTTON_P			112
# endif

#endif
