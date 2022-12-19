INCS=\
	AocUtils.h

OBJS=\
	AocUtils.o\
	main.o

CFLGS=-c -mconsole -O2 -I ..\..\..\libdave64

LIBS=..\..\..\libdave64\libdave.a

LIBS2=/d/progs/raylib/raylib/build/raylib/libraylib.a /d/progs/raylib/raylib/build/raylib/external/glfw/src/libglfw3.a -lopengl32 -lgdi32 -lwinmm

all : day12.exe day12vis.exe

day12.exe : $(OBJS) $(INCS)
	g++ -o day12.exe -mconsole $(OBJS) $(LIBS) 

day12vis.exe : mainVis.o AocUtils.o
	g++ -o day12vis.exe mainVis.o AocUtils.o $(LIBS) $(LIBS2)

main.o : main.cpp $(INCS)
	g++ $(CFLGS) main.cpp

mainVis.o : mainVis.cpp $(INCS)
	g++ $(CFLGS) -I /d/progs/raylib/raylib/src mainVis.cpp

AocUtils.o : AocUtils.cpp $(INCS)
	g++ $(CFLGS) AocUtils.cpp

clean :
	rm *.o
