# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Executable name
EXEC = nwaycache

# Source directory
SRCDIR = src

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Header files
HDRS = $(wildcard $(SRCDIR)/*.hpp)

# Default target
all: $(EXEC)

# Compile and link
$(EXEC): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

# Clean
clean:
	rm -f $(EXEC)
