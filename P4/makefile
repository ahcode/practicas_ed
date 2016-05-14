OBJETOS = main.o Lado.o Grafo.o funciones.o
CPPFLAGS = -c -g -Wall -ansi

main.out: $(OBJETOS)
	g++ -o main.out $(OBJETOS)

Lado.o: Lado.cpp Lado.hpp Vertice.hpp
	g++ $(CPPFLAGS) Lado.cpp

Grafo.o: Grafo.cpp Grafo.hpp Lado.o Vertice.hpp
	g++ $(CPPFLAGS) Grafo.cpp

funciones.o: funciones.cpp funciones.hpp Grafo.o
	g++ $(CPPFLAGS) funciones.cpp

main.o: main.cpp Grafo.o funciones.o
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f $(OBJETOS)

rmexe:
	rm -f main.out
