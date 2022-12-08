INCS=\
	AocUtils.h

OBJS=\
	AocUtils.o\
	main.o

CFLGS=-c -mconsole -O2 -I ..\..\..\libdave64

LIBS=..\..\..\libdave64\libdave.a

day7.exe : $(OBJS) $(INCS)
	g++ -o day7.exe -mconsole $(OBJS) $(LIBS) 

main.o : main.cpp $(INCS)
	g++ $(CFLGS) main.cpp

AocUtils.o : AocUtils.cpp $(INCS)
	g++ $(CFLGS) AocUtils.cpp

clean :
	rm *.o
