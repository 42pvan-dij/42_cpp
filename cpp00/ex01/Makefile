NAME 	= phonebook
CC 		= c++
FLAGS 	= -Wall -Wextra -Werror -std=c++98
SRC 	= Phonebook.cpp Phonebookmain.cpp Contacts.cpp

OBJS	= ${SRC:.cpp=.o}

all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, re, fclean