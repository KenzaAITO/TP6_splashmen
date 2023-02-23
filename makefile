SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
#CFLAGS= -Wall -g2 -fPIC  # -DDEBUG
CFLAGS= -W1 -g2 -fPIC  # -DDEBUG
#LDFLAGS= -ldl -l/Users/cecilia/Desktop/projet_ecole/rebornExplosion/SDL2
LDFLAGS= -l/Users/cecilia/Desktop/projet_ecole/rebornExplosion/SDL2
EXE=splash

players:
	cd pl && $(MAKE)

all: players $(OBJS)
	@echo $(SRCS) 
	clang  $(OBJS) $(LDFLAGS) -o $(EXE)

clean_pl:
	cd pl && $(MAKE) clean

clean_all: clean 
	cd pl && $(MAKE) clean

tp5: $(OBJS)
	clang  $(OBJS) -ldl -l/Users/cecilia/Desktop/projet_ecole/rebornExplosion/SDL2 -lsplash -o $(EXE)

liba: $(OBJS)
	ar crs libsplash.a actions.o player.o world.o render.o bomb.o

affiche:
	@echo TOTO

libso: affiche all 
	clang -shared -o libsplash.so actions.o main.o player.o world.o

clean: 
	$(DEL) -f core
	rm -f *.a
	rm -f *.so
	rm -f $(OBJS)
	rm -f $(EXE)


