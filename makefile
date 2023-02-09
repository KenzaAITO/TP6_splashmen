# makefile
SRCS=$(wildcard *.c)#variable source tu met tous les objets
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -g2 -fPIC -I lSDL2 # -DDEBUG
LDFLAGS= -ldl -lSDL2
EXE=splash

players:
	cd pl && $(MAKE)

all: players $(OBJS) #tous les .c sont appele grace a SRCS
	@echo $(SRCS) 
	gcc  $(OBJS) $(LDFLAGS) -o $(EXE)
	@echo LIB

clean_pl:
	cd pl && $(MAKE) clean

clean_all: clean 
	cd pl && $(MAKE) clean

tp5: $(OBJS)
	gcc  $(OBJS) -ldl -lSDL2 -lsplash -o $(EXE)

liba: $(OBJS)
	ar crs libsplash.a action.o player.o world.o render.o bomb.o

affiche:
	@echo TOTO

libso: affiche all 
	gcc -shared -o libsplash.so action.o main.o player.o world.o

clean: 
	$(DEL) -f core 
#core dump de la meoire au moment du crash va avec le debugger  
	rm -f *.a
	rm -f *.so
	rm -f $(OBJS)
	rm -f $(EXE)

#lib asan pour eviter fuite de memoire com valgrind 