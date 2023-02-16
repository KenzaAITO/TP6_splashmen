# makefile
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -g2 -fPIC -DDEBUG
#LDFLAGS= -ldl -lSDL2
LDFLAGS = -L/Users/cecilia/Desktop/SDL2
DFLAGS= actions.o init.o main.o player.o render.o world.o -o splash /Users/cecilia/Desktop/SDL2
EXE=splash

players:
	cd pl && $(MAKE)
	@echo PLAYER

all: players $(OBJS)
	@echo $(SRCS) 
#	gcc  $(OBJS) $(LDFLAGS) -o $(EXE)
#	gcc  $(OBJS) -o $(EXE)
	gcc  $(OBJS) $(DFLAGS) -o $(EXE)
	@echo FIN ALL

clean_pl:
	cd pl && $(MAKE) clean
	@echo CLEAN_PL

clean_all: clean 
	cd pl && $(MAKE) clean
	@echo CLEAN_ALL

tp5: $(OBJS)
	gcc  $(OBJS) -l -lSDL2 -lsplash -o $(EXE)
	@echo TP5

liba: $(OBJS)
	ar crs libsplash.a actions.o player.o world.o render.o bomb.o
	@echo LIBA

affiche:
	@echo AFFICHAGE

libso: affiche all 
	gcc -shared -o libsplash.so actions.o main.o player.o world.o
	@echo FIN LIBSO
clean: 
	$(DEL) -f core
	rm -f *.a
	rm -f *.so
	rm -f $(OBJS)
	rm -f $(EXE)
	@echo REMOVE

