all: MonomioMain.out PolinomioMain.out

MonomioMain.out: MonomioMain.cpp Monomio.cpp
	g++ MonomioMain.cpp Monomio.cpp -o MonomioMain.out

PolinomioMain.out: PolinomioMain.cpp Polinomio.cpp Monomio.cpp
	g++ PolinomioMain.cpp Polinomio.cpp Monomio.cpp -o PolinomioMain.out

clean:
	rm -f MonomioMain.out PolinomioMain.out
