NAME := libftprintf.a
CC := cc
CC_FLAGS := -Wall -Werror -Wextra

#AR SYSTEM
AR := ar
AR_FLAGS := -csr

# Lista de archivos fuente (.c)
FT_FILES := ft_printf.c \
ft_handle_args.c \
ft_printhex.c \
ft_printnbr.c \
ft_uprintnbr.c \
ft_utils.c \

#Archivo de testeo para funciones
FT_FTEST := main.c

#Solamente para usar la libreria en main.c
INCLUDES := ft_printf.h

# Generar nombres de archivos objeto (.o)
OBJ := $(FT_FILES:%.c=%.o)
#OBJ_BONUS := $(FT_FILES_BONUS:%.c=%.o)
#Creación librería
all: $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $?

#Creación archivos objeto
%.o: %.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

#Clean
clean :
	rm -f $(OBJ) $(OBJ_BONUS)

#FClean
fclean : clean
	rm -f $(NAME)

#FClean y rehacer todo
re : fclean all

#bonus: $(NAME)
#$(NAME) : $(OBJ) $(OBJ_BONUS)
#	$(AR) $(AR_FLAGS) $(NAME) $?

test:  all
	$(CC) $(CC_FLAGS -g) -I $(INCLUDES) -o $@ main.c $(NAME)
	$(clean)

testc: all test clean

.PHONY: all clean fclean re test bonus