NAME = wordle

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)/$(INCLUDES)

DFLAGS = -MMD -MP

SRC_DIR = src

BUILD_DIR = .build

include src.mk

INCLUDES = includes

LIBFT = libft.a

LIBFT_DIR = libft

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(LIBFT_DIR)/$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(MAKE) -C $(LIBFT_DIR)/ clean
	$(RM) -r $(BUILD_DIR)


.PHONY: fclean
fclean : clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE:
