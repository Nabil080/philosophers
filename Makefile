######################## SETTINGS ########################

NAME = philo

CC = cc

FLAGS = #-Wall -Wextra -Werror

LINKFLAGS = -lpthread

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

MAKEFLAGS += --no-print-directory

######################## SOURCES ########################

SRCS_NAMES =	main.c \
				init.c \
				dinner.c \
				utils.c \
				libft.c \
				getters.c

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

HEADERS =	includes/philo.h \
			includes/defines.h

######################## BASIC RULES ########################

all : 
	${MAKE} -j ${NAME}

re : fclean
	${MAKE} all

clean :
	${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
	rm -f ${NAME}

norm :
	${foreach lib, ${LIBS}, ${MAKE} norm -C ${lib}}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCLUDES}

######################## COMPILATION ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@ ${LINKFLAGS}

debug : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} -g3 -fsanitize=address ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o ${NAME} ${LINKFLAGS}

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.c ${HEADERS}
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

######################## TEST ########################

test : base

base : all
	./${NAME} 10 410 200 200

ez : all
	./${NAME} 2 999999 200 200

odd : all
	./${NAME} 5 999999 200 200

ded : all
	./${NAME} 10 200 200 200

hell : all
	valgrind --tool=helgrind ./${NAME} 2 9999 200 200

leak : all
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} 2 99999 200 200
