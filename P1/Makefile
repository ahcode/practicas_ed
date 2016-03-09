all: MonomioMain.out PolinomioMain.out

MonomioMain.out: MonomioMain.cc Monomio.cc
	g++ MonomioMain.cc Monomio.cc -o MonomioMain.out

PolinomioMain.out: PolinomioMain.cc Polinomio.cc Monomio.cc
	g++ PolinomioMain.cc Polinomio.cc Monomio.cc -o PolinomioMain.out

clean:
	rm -f MonomioMain.out PolinomioMain.out
