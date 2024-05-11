CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = world.c 
LINKER = -lSDL2 -lSDL2_image 
OBJS = main.c  
EXEC = exe 

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LINKER) $(SRCS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) 

