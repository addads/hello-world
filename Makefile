#CFLAGS   = /nologo /W4 /EHsc /Za

#all : ConsoleApplication18
 
#ConsoleApplication18.exe : ConsoleApplication18.obj
#	$(CPP) $(CFLAGS) /Fe$@.exe $**

	

#clean :
#	del *.exe

ifeq ($(OS),Windows_NT)
	RM = del -f
else
	RM = rm -f
endif

CC = g++

all: exe 

exe : ConsoleApplication18.o
	$(CC) -o ConsoleApplication18 ConsoleApplication18.o

clean:
	$(RM) *o *exe ConsoleApplication18
