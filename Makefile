SRCS = $(wildcard *.c dll/*.c operations/*.c helper/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Iinclude -g

apc: $(OBJS)
	gcc -o apc $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f apc.exe $(OBJS)