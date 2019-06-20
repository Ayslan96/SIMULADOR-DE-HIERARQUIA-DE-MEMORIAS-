PROG = ProjetoIAC
CC = g++
CPPFLAGS = -O0 -pedantic -Wall -std=c++11 
OBJS = memoria.o cache.o cpu.o sistema.o


$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG) 

memoria.o:
	$(CC) $(CPPFLAGS) -c src/memoria.cpp

cache.o:
	$(CC) $(CPPFLAGS) -c src/cache.cpp 

cpu.o:
	$(CC) $(CPPFLAGS) -c src/cpu.cpp

sistema.o:
	$(CC) $(CPPFLAGS) -c src/sistema.cpp 

clean:
	rm -f core $(PROG) $(OBJS)