# ══ Names ═══════════════════════════════════════════════════════════════════ #

NAME                = cub3D

# ══ Colors ══════════════════════════════════════════════════════════════════ #

DEL_LINE            = \033[2K
ITALIC              = \033[3m
BOLD                = \033[1m
DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
WHITE               = \033[0;97m
BLACK               = \033[0;99m
ORANGE              = \033[38;5;209m
BROWN               = \033[38;2;184;143;29m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

# ══ Compilation ═════════════════════════════════════════════════════════════ #

CC                  = clang
AR                  = ar rcs
RM                  = rm -f
MKD                 = mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #

READ_DIR            = ./read_map
MAPS_DIR            = ./maps
MAPS_ERR_DIR        = ./maps_error
LIBRARIES           = ./libs
OBJ_DIR             = ./obj
LIBFT_DIR           = libft
PRINTFT_DIR         = printf
GNL_DIR             = gnl
INCLUDES_DIR        = ./includes
MLX42_LIB           = ./MLX42/lib
MLX42_INCLUDE       = ./MLX42/include/MLX42
PARSING_DIR         = ./parser
PLAY_DIR            = ./play
CHECKER_DIR         = ./checker_map
INIT_DIR            = ./init
WINDOW_DIR          = ./full_window

# ══ Library Archives ════════════════════════════════════════════════════════ #

LIBFT_A             = ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A           = ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
GNL_A               = ${LIBRARIES}/${GNL_DIR}/libgnl.a
LIBMLX42_A          = ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #

CFLAGS              = -Wall -Werror -Wextra  #-fsanitize=address -g #
IFLAGS              = -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS              = -L${LIBRARIES}/${LIBFT_DIR} -lft \
                      -L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
                      -L${LIBRARIES}/${GNL_DIR} -lgnl \
                      -L$(MLX42_LIB) -lmlx42 -lglfw -ldl -lm -lpthread

# ══ Sources ═════════════════════════════════════════════════════════════════ #

PARSING             = ${PARSING_DIR}/parser.c

CHECKER             = ${CHECKER_DIR}/checker_borders.c \
                      ${CHECKER_DIR}/checker_inside.c \
                      ${CHECKER_DIR}/checker_spaces.c

PLAY                = ${PLAY_DIR}/main.c

INIT                = ${INIT_DIR}/init_structures.c \
                      ${INIT_DIR}/init_walls_and_rays.c

READ                = ${READ_DIR}/checker.c \
                      ${READ_DIR}/error.c \
                      ${READ_DIR}/manage_color.c \
                      ${READ_DIR}/map.c \
                      ${READ_DIR}/utils.c \
                      ${READ_DIR}/textures.c \
                      ${READ_DIR}/checker_2.c \
                      ${READ_DIR}/free.c \
                      ${READ_DIR}/update_map.c \
                      ${READ_DIR}/utils_2.c

WINDOW              = ${WINDOW_DIR}/ft_textures_mlx.c \
                      ${WINDOW_DIR}/ft_player.c \
                      ${WINDOW_DIR}/rays.c \
                      ${WINDOW_DIR}/callback.c \
                      ${WINDOW_DIR}/ft_movements.c \
                      ${WINDOW_DIR}/ft_calculations.c \
                      ${WINDOW_DIR}/ft_painting.c

OBJ_PARSING         = $(patsubst ${PARSING_DIR}/%.c, ${OBJ_DIR}/%.o, ${PARSING})
OBJ_PLAY            = $(patsubst ${PLAY_DIR}/%.c, ${OBJ_DIR}/%.o, ${PLAY})
OBJ_INIT            = $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INIT})
OBJ_READ            = $(patsubst ${READ_DIR}/%.c, ${OBJ_DIR}/%.o, ${READ})
OBJ_CHECKER         = $(patsubst ${CHECKER_DIR}/%.c, ${OBJ_DIR}/%.o, ${CHECKER})
OBJ_WINDOW          = $(patsubst ${WINDOW_DIR}/%.c, ${OBJ_DIR}/%.o, ${WINDOW})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #

all: ${NAME}

${NAME}: ${LIBFT_A} ${PRINTFT_A} ${GNL_A} ${LIBMLX42_A} ${OBJ_PARSING} \
                                    ${OBJ_PLAY} ${OBJ_INIT} \
                                    ${OBJ_READ} ${OBJ_CHECKER} ${OBJ_WINDOW}
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_PARSING} \
                                    ${OBJ_PLAY} ${OBJ_INIT} ${OBJ_CHECKER} ${OBJ_WINDOW}\
                                    ${OBJ_READ} ${LFLAGS}

${OBJ_DIR}/%.o: ${PARSING_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${PLAY_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${WINDOW_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${READ_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CHECKER_DIR}/%.c
	@${MKD} $(dir $@)
	@echo "Compiling $<..."
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files!$(DEF_COLOR)"
	@find ${OBJ_DIR} -name "*.o" -type f -delete
	@echo "$(RED)Object files removed! $(DEF_COLOR)"

fclean: clean
	@echo "$(YELLOW)Removing binaries!$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)Binaries removed! $(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re