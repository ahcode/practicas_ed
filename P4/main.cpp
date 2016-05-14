#include <iostream>
#include <limits>
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
  float f1, f2;
	bool error, salir=false;
	std::string cad;
	std::vector< std::vector<float> > mdist;
	std::vector< std::vector<int> > mint;
  Vertice v1;
  Vertice v2;
  do{
    error=false;
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
        BORRAR;
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
        if(gr.estaVacio()){
          cout << "\n<< El grafo está vacío >>\n\n";
          continuar();
          BORRAR;
          break;
        }
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
        if(gr.estaVacio()){
          cout << "\n<< El grafo está vacío >>\n\n";
          continuar();
          BORRAR;
          break;
        }
        floyd(gr,mdist,mint);
        error=false;
        do{
          NEGRITA; cout << "0."; NORMAL; cout << " Volver\n";
          NEGRITA; cout << "1."; NORMAL; cout << " Mostrar suma de distancias desde cada vértice\n";
          NEGRITA; cout << "2."; NORMAL; cout << " Mostrar camino mínimo entre dos vértices\n";
          if(error)
            cout << "<< La opción introducida no es válida >>";
          SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
          cin >> op;
          cin.ignore(256,'\n');
          BORRAR;
          error=true;
        }while(op<0 || op>2);
        switch(op){
          case 1:
            f2=std::numeric_limits<double>::infinity();
            for (int i=0;i<(int)mdist.size();i++){
              gr.goTo(i);
              v1=gr.verticeActual();
              cout << "Vértice " << v1.getDato() << " = ";
              f1=0;
              for (int j=0;j<(int)mdist.size();j++)
                f1+=mdist[i][j];
              cout << f1 << "\n";
              if (f1<f2){
                f2=f1;
                v2=v1;
              }
            }
            cout << "\nEl vértice con menor suma de distancias a los demás es: " << v2.getDato() << " (" << f2 << ")\n\n";
            continuar();
            BORRAR;
            break;
          case 2:
            error=false;
            do{
              if(error)
                cout << "<< El vértice introducido no existe >>";
              SUBRAYADO; cout << "\nVértice inicial"; NORMAL; cout << " = ";
              getline(cin,cad);
              BORRAR;
              error=true;
            }while(!gr.buscarVertice(cad));
            v1=gr.verticeActual();
            error=false;
            do{
              if(error)
                cout << "<< El vértice introducido no existe >>";
              SUBRAYADO; cout << "\nVértice final"; NORMAL; cout << " = ";
              getline(cin,cad);
              BORRAR;
              error=true;
            }while(!gr.buscarVertice(cad));
            v2=gr.verticeActual();
            mostrarCaminoDistancia(gr,mdist,mint,v1,v2);
            cout << "\n";
            continuar();
            BORRAR;
            break;
        }
		}
	}while(!salir);
	return 0;
}
