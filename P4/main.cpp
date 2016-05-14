#include <iostream>
#include "Grafo.hpp"
#include "funciones.hpp"
#include "macros.hpp"

using namespace ed;
using std::cout;
using std::cin;

/*!
\brief Hace una pausa para que el usuario pueda ver los datos en pantalla
\note Para continuar debe pulsar enter
*/
void continuar(){
  INVERSO; cout << "Presiona enter para continuar..."; NORMAL;
	getchar();
	BORRAR;
}

int main(){
	BORRAR;
	Grafo gr;
	int op;
	bool error, salir=false;
	std::string cad;
	std::vector< std::vector<float> > mdist;
	std::vector< std::vector<int> > mint;
  Vertice v1;
  Vertice v2;
  do{
    error=0;
    do{
      NEGRITA; cout << "0."; NORMAL; cout << " Salir\n";
			NEGRITA; cout << "1."; NORMAL; cout << " Cargar grafo desde fichero\n";
			NEGRITA; cout << "2."; NORMAL; cout << " Mostrar el grafo\n";
			NEGRITA; cout << "3."; NORMAL; cout << " Algoritmo de Floyd\n";
      if(error)
				cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
			cin >> op;
      cin.ignore(256,'\n');
			BORRAR;
			error=true;
    }while(op<0 || op>3);

		switch(op){
			case 0:
				salir=true;
				break;
			case 1:
				SUBRAYADO; cout << "\nNombre del fichero"; NORMAL; cout << " = ";
				getline(cin, cad);
				BORRAR;
				if(!gr.cargarFichero(cad)){
					NEGRITA; cout << "\nEl fichero no ha sido cargado\n"; NORMAL;
					cout << "<< Error al abrir el fichero >>\n\n";
				}else{
					NEGRITA; cout << "\nEl fichero ha sido cargado con éxito\n\n"; NORMAL;
				}
				continuar();
				BORRAR;
				break;
			case 2:
        //Listar Vértices
        NEGRITA; cout << "\tVERTICES:\n"; NORMAL;
        for (int i=0;i<gr.numVertices();i++){
          gr.goTo(i);
          cout << gr.verticeActual().getDato() << "\n";
        }
        //Listar Lados
        NEGRITA; cout << "\n\tLADOS:\n"; NORMAL;
        if (gr.esDirigido()){
          for (int i=0;i<gr.numVertices();i++){
            gr.goTo(i);
            v1=gr.verticeActual();
            for (int j=0;j<gr.numVertices();j++){
              gr.goTo(j);
              v2=gr.verticeActual();
              if(gr.adyacente(v1,v2))
                cout << v1.getDato() << " -> " << v2.getDato() << " = " << gr.getLado(v1,v2).getDato() << "\n";
            }
          }
        }else{
          for (int i=0;i<gr.numVertices();i++){
            gr.goTo(i);
            v1=gr.verticeActual();
            for (int j=i+1;j<gr.numVertices();j++){
              gr.goTo(j);
              v2=gr.verticeActual();
              if(gr.adyacente(v1,v2))
                cout << v1.getDato() << " <-> " << v2.getDato() << " = " << gr.getLado(v1,v2).getDato() << "\n";
            }
          }
        }
        cout << "\n";
        continuar();
        BORRAR;
				break;
			case 3:
				floyd(gr,mdist,mint);
				gr.goTo(12);
				v1=gr.verticeActual();
				gr.goTo(5);
				v2=gr.verticeActual();
				mostrarCaminoDistancia(gr,mdist,mint,v1,v2);
				continuar();
				break;
		}
	}while(!salir);
	return 0;
}
