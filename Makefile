CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = camera.c world.c player.c music.c physic.c
LINKER = -lSDL2 
OBJS = main.c  
EXEC = exe 

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LINKER) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) 

