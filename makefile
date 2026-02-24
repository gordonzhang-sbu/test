# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# All C source files
SRCS = codeL6_1.c codeL6_2.c codeL6_3.c codeL6_4.c codeL6_5.c \
       codeL6_6.c codeL6_7.c codeL6_8.c codeL6_9.c \
       codeL6_10.c codeL6_11.c codeL6_12.c codeL6_13.c

# Generate executable names automatically (remove .c)
TARGETS = $(SRCS:.c=)

# Default target
all: $(TARGETS)

# Rule to build each executable
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -f $(TARGETS)
