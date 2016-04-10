all: DonanteMain.out DonantesMain.out

DonanteMain.out: DonanteMain.cpp DonanteInterfaz.hpp Donante.hpp Donante.cpp macros.hpp
	g++ DonanteMain.cpp Donante.cpp -o DonanteMain.out

DonantesMain.out: DonantesMain.cpp DonanteInterfaz.hpp Donante.hpp Donante.cpp DonantesInterfaz.hpp Donantes.hpp Donantes.cpp ListaDonantes.hpp ListaDonantes.cpp macros.hpp ficherosDonantes.hpp ficherosDonantes.cpp
	g++ DonantesMain.cpp Donantes.cpp Donante.cpp ListaDonantes.cpp ficherosDonantes.cpp -o DonantesMain.out

clean:
	rm -f DonanteMain.out
	rm -f DonantesMain.out
