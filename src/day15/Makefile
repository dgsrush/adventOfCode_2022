INCS=\
	AocUtils.h\
	FuncPool.h

OBJS=\
	AocUtils.o\
	FuncPool.o\
	main.o

CFLGS=-c -mconsole -O2 -I ..\..\..\libdave64

LIBS=..\..\..\libdave64\libdave.a

day15.exe : $(OBJS) $(INCS)
	g++ -o day15.exe -mconsole $(OBJS) $(LIBS) 

main.o : main.cpp $(INCS)
	g++ $(CFLGS) main.cpp

AocUtils.o : AocUtils.cpp $(INCS)
	g++ $(CFLGS) AocUtils.cpp

FuncPool.o : FuncPool.cpp $(INCS)
	g++ $(CFLGS) FuncPool.cpp

clean :
	rm *.o
