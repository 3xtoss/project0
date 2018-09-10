#@author Jared Mulhausen
#Makefile for Project 0


CC = gcc
CFLAGS = -Wall
OBJS = project0.o

project0: $(OBJS)
		$(CC) -o project0 $(OBJS)
