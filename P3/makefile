OBJETOS = Donante.o MonticuloDonantes.o MonticuloDonantesMain.o
CPPFLAGS = -c -g -Wall -ansi

MonticuloDonantesMain.out: $(OBJETOS)
	g++ -o MonticuloDonantesMain.out $(OBJETOS)

Donante.o: Donante.cpp Donante.hpp DonanteInterfaz.hpp macros.hpp
	g++ $(CPPFLAGS) Donante.cpp

MonticuloDonantes.o: MonticuloDonantes.cpp MonticuloDonantes.hpp Donante.o macros.hpp
	g++ $(CPPFLAGS) MonticuloDonantes.cpp

MonticuloDonantesMain.o: MonticuloDonantesMain.cpp MonticuloDonantes.o Donante.o macros.hpp
	g++ $(CPPFLAGS) MonticuloDonantesMain.cpp

clean:
	rm -f $(OBJETOS)

rmexe:
	rm -f MonticuloDonantesMain.out
