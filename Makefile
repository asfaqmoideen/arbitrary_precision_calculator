SRCS = $(wildcard *.c dll/*.c operations/*.c helper/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Iinclude -g

final: $(OBJS)
	gcc -o final $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f final.exe $(OBJS)