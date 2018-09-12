#@author Jared Mulhausen
#Makefile for Project 0
#Documentation, for creating this Makefile, was found under the C4JAVA-2.pdf shared
#on the class website.


CC = gcc
CFLAGS = -Wall
OBJS = project0.o

project0: $(OBJS)
		$(CC) -o project0 $(OBJS)
