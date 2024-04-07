# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Executable name
EXEC = nwaycache

# Source directory
SRCDIR = src

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Default target
all: $(EXEC)

# Compile and link
$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

# Clean
clean:
	rm -f $(EXEC)
