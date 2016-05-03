OBJETOS = main.o Lado.o Grafo.o
CPPFLAGS = -c -g -Wall -ansi

main.out: $(OBJETOS)
	g++ -o main.out $(OBJETOS)

Lado.o: Lado.cpp Lado.hpp Vertice.hpp
	g++ $(CPPFLAGS) Lado.cpp

Grafo.o: Grafo.cpp Grafo.hpp Lado.o Vertice.hpp
	g++ $(CPPFLAGS) Grafo.cpp

main.o: Grafo.o
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f $(OBJETOS)

rmexe:
	rm -f main.out
