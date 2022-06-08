VPATH = ../src

test : main.o linked_list.o soft_timer.o
	gcc -o test main.o linked_list.o soft_timer.o

main.o : main.c
	gcc -c main.c

linked_list.o : linked_list.c basic_types.h
	gcc  -c ../src/linked_list.c

soft_timer.o : soft_timer.c soft_timer.h
	gcc -c ../src/soft_timer.c

clean :
	rm test main.o linked_list.o soft_timer.o
