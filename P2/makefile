OBJETOS_DONANTE = Donante.o DonanteMain.o
OBJETOS_DONANTES =  Donante.o Donantes.o ListaDonantes.o ficherosDonantes.o DonantesMain.o
CPPFLAGS = -g -Wall -ansi

all: DonanteMain.out DonantesMain.out

DonanteMain.out: $(OBJETOS_DONANTE)
	g++ -o DonanteMain.out $(OBJETOS_DONANTE)

DonantesMain.out: $(OBJETOS_DONANTES)
	g++ -o DonantesMain.out $(OBJETOS_DONANTES)

Donante.o: Donante.cpp Donante.hpp DonanteInterfaz.hpp macros.hpp
	g++ -c $(CPPFLAGS) Donante.cpp

ListaDonantes.o: ListaDonantes.cpp ListaDonantes.hpp Donante.hpp
	g++ -c $(CPPFLAGS) ListaDonantes.cpp

Donantes.o: Donantes.cpp Donantes.hpp DonantesInterfaz.hpp macros.hpp Donante.hpp ListaDonantes.hpp
	g++ -c $(CPPFLAGS) Donantes.cpp

ficherosDonantes.o: ficherosDonantes.cpp ficherosDonantes.hpp Donantes.hpp Donante.hpp
	g++ -c $(CPPFLAGS) ficherosDonantes.cpp

DonanteMain.o: DonanteMain.cpp Donante.hpp macros.hpp
	g++ -c $(CPPFLAGS) DonanteMain.cpp

DonantesMain.o: DonantesMain.cpp Donante.hpp Donantes.hpp ListaDonantes.hpp ficherosDonantes.hpp macros.hpp
	g++ -c $(CPPFLAGS) DonantesMain.cpp

clean:
	rm -f $(OBJETOS_DONANTES) $(OBJETOS_DONANTE)

rmexe:
	rm -f DonanteMain.out DonantesMain.out
