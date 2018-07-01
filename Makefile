NAME = ft_retro

CC = clang++

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -lncurses

SRC = Bullet.cpp Enemy.cpp Game.cpp GameEntity.cpp Player.cpp main.cpp

all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
