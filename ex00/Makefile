# ==== CONFIG ====
NAME     = ex0
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM       = rm -f

# ==== COLORS ====
GREEN    = \033[1;32m
BLUE     = \033[1;34m
YELLOW   = \033[1;33m
RED      = \033[1;31m
RESET    = \033[0m

# ==== SOURCES & OBJECTS ====
SRCS     =  main.cpp Fixed.cpp
OBJS     = $(SRCS:.cpp=.o)

# ==== TARGETS ====

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)[LINK]$(RESET) Creating executable: $(NAME)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)[DONE]$(RESET) Build finished!"

%.o: %.cpp
	@echo "$(YELLOW)[COMP]$(RESET) Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removing executable..."
	@$(RM) $(NAME)

re: fclean all

# ==== PHONY ====
.PHONY: all clean fclean re
