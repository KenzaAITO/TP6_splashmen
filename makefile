SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
#CFLAGS= -Wall -g2 -fPIC  # -DDEBUG
CFLAGS= -Wall -g2 -fPIC# -DDEBUG
#LDFLAGS= -ldl -l/Users/cecilia/Desktop/projet_ecole/rebornExplosion/SDL2
LDFLAGS= -I/usr/local/Cellar/sdl2/2.26.3/include/* -L/usr/local/Cellar/sdl2/2.26.3/lib -lSDL2 -lsplash -o $(EXE)

EXE=splash

players:
	cd pl && $(MAKE)

all: players libsotest $(OBJS)
	@echo $(SRCS)
	clang  $(OBJS) $(LDFLAGS) -o $(EXE)

clean_pl:
	cd pl && $(MAKE) clean

clean_all: clean 
	cd pl && $(MAKE) clean

tp5: $(OBJS)
	clang -Wall -g2 -fPIC $(OBJS) -ldl -I/usr/local/Cellar/sdl2/2.26.3/include -L/usr/local/Cellar/sdl2/2.26.3/lib -lSDL2 -lsplash -o $(EXE)


liba: $(OBJS)
	ar crs libsplash.a actions.o player.o world.o render.o 

affiche:
	@echo TOTO

libso: affiche all 
	clang -shared -o libsplash.so actions.o main.o player.o world.o

libsotest: $(OBJS)
	cd .. && clang $(CFLAGS) $(OBJS)
	clang -ldl -I/usr/local/Cellar/sdl2/2.26.3/include -L/usr/local/Cellar/sdl2/2.26.3/lib -lSDL2 -shared -o libsplash.so actions.o main.o player.o world.o

clean: 
	$(DEL) -f core
	rm -f *.a
	rm -f *.so
	rm -f *.gho
	rm -f $(OBJS)
	rm -f $(EXE)


