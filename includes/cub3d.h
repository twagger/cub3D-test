/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:35:12 by twagner           #+#    #+#             */
/*   Updated: 2022/01/25 10:16:28 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h" 

/*
** PARAMS
*/

# define PLAYER_CHAR "NSWE"
# define VALID_CHAR "NSWE 01"

// A call to free_gnl_buffer() frees the buffer of GNL

# define free_gnl_buffer() ft_get_next_line(0, NULL, 1)



typedef enum e_return_codes
{
	OK = 0,
	NO = 0,
	YES = 1,
	KO = 1
}	t_return_codes;

// Used to count the number of parameters in the parser

enum	e_parameter_bit_codes {
	ALL_PARAMS_ARE_SET = 63,
	NO_TEXTURE_CODE = 32,
	SO_TEXTURE_CODE = 16,
	WE_TEXTURE_CODE = 8,
	EA_TEXTURE_CODE = 4,
	F_COLOR_CODE	= 2,
	C_COLOR_CODE	= 1,
};

enum e_exit_codes {
	SUCCESS = 0,
	MAP_ERROR,
	PARAM_ERROR,
	FILE_ERROR,
	MALLOC_FAIL,
	MLX_FAIL,
	USER_INTERRUPT,
	NUMBER_OF_EXIT_CODES,
};


/* for floor and ceiling colors
blue = (RGB >> 16) & 0xFF;
green = (RGB >> 8) & 0xFF;
red = RGB & 0xFF;

new_RGB = (blue << 16) | (green << 8) | red;
*/

typedef struct s_param
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		col_floor;
	int		col_ceiling;
	char	**map;
	int		width;
	int		height;
}			t_param;

/*
** FUNCTIONS
*/

/*
** Error Handling
*/
int	exit_clean(int error_msg, int fd, char **to_free, t_param *param);

/*
** parser
*/
int		line_param_code(char *line);
bool	is_cub_file(char *file);
bool	are_parameters_ok(int fd);
int		param_controller(int fd);
bool	is_map_ok(int fd, int *longest_map_width, int *map_height);
int		map_controller(int fd, int *longest_map_width, int *map_height);
int		init_param(char *file, t_param *param, int height, int width);
bool	is_valid_parameter(char *line, char param_counter, char code);
/*
** Resource Free
*/
void	free_two_d_array(char **tab);
void    free_param(t_param *param);

/*
** Test functions
*/
void	print_param(t_param *param);
void	print_map(t_param *param);
#endif