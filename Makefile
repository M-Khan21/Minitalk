NAME = SIG
CLIENT = client
SERVER = server
FLAGS = -Wall -Wextra -Werror


all: $(SERVER) $(CLIENT)
$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
    gcc $(CFLAGS) server.c -o $(SERVER)
$(CLIENT):
    gcc $(CFLAGS) client.c client_utils.c -o $(CLIENT)

clean:
    rm -f $(SERVER) $(CLIENT)
fclean: clean
re: fclean all
.PHONY: all clean fclean re