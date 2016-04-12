OBJETOS = Donante.o MonticuloDonantes.o MonticuloDonantesMain.o
CPPFLAGS = -g -Wall -ansi

MonticuloDonantesMain.out: $(OBJETOS)
	g++ -o MonticuloDonantesMain.out $(OBJETOS)

Donante.o: Donante.cpp Donante.hpp DonanteInterfaz.hpp macros.hpp
	g++ -c $(CPPFLAGS) Donante.cpp

MonticuloDonantes.o: MonticuloDonantes.cpp MonticuloDonantes.hpp Donante.o macros.hpp
	g++ -c $(CPPFLAGS) MonticuloDonantes.cpp

MonticuloDonantesMain.o: MonticuloDonantesMain.cpp MonticuloDonantes.o Donante.o macros.hpp
	g++ -c $(CPPFLAGS) MonticuloDonantesMain.cpp

clean:
	rm -f $(OBJETOS)

rmexe:
	rm -f MonticuloDonantesMain.out
