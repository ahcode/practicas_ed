/*!
\file MonticuloDonantesMain.cpp
\brief Programa principal para probar la clase MonticuloDonantes
\author Álvaro Herrero Pérez
\date 22/04/2016
*/

/*!
\mainpage Práctica 3 de la asignatura Estructura de Datos
\author Álvaro Herrero Pérez
\date 22 de Abril de 2016
*/

#include <iostream>
#include <string>
#include "MonticuloDonantes.hpp"
#include "Donante.hpp"
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

/*!
\brief Programa principal para probar la clase Donantes
*/
int main(){
  BORRAR;
  MonticuloDonantes monticulo;
  Donante d;
  int op, n;
  std::string cad;
  bool error, salir=false;
  do{
    error=0;
    do{
      NEGRITA; cout << "1."; NORMAL; cout << " Comprobar si el montículo está vacío\n";
			NEGRITA; cout << "2."; NORMAL; cout << " Cargar donantes desde fichero\n";
			NEGRITA; cout << "3."; NORMAL; cout << " Grabar donantes en fichero\n";
      NEGRITA; cout << "4."; NORMAL; cout << " Insertar donante\n";
			NEGRITA; cout << "5."; NORMAL; cout << " Mostrar el donante en la cima\n";
      NEGRITA; cout << "6."; NORMAL; cout << " Realizar donaciones\n";
      NEGRITA; cout << "7."; NORMAL; cout << " Borrar la cima\n";
      NEGRITA; cout << "8."; NORMAL; cout << " Vaciar montículo\n";
			NEGRITA; cout << "9."; NORMAL; cout << " Salir\n\n";
      if(error)
				cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
			cin >> op;
      cin.ignore(256,'\n');
			BORRAR;
			error=true;
    }while(op<1 || op>9);

    switch(op){
      case 1:
        if(monticulo.vacio()){
          NEGRITA; cout << "\nNo hay donantes almacenados\n\n"; NORMAL;
        }else{
          NEGRITA; cout << "\nHay donantes almacenados\n\n"; NORMAL;
        }
        continuar();
        break;
      case 2:
        SUBRAYADO; cout << "\nNombre del fichero"; NORMAL; cout << " = ";
        getline(cin, cad);
        BORRAR;
        try{
          monticulo.cargarFichero(cad);
        }catch(int i){
          NEGRITA; cout << "\nEl fichero no ha sido cargado\n"; NORMAL;
          switch(i){
            case 1:
              cout << "<< Error al abrir el fichero >>";
              break;
            case 2:
              cout << "<< Error al intentar añadir un grupo sanguíneo no válido >>";
              break;
            case 3:
              cout << "<< Error al intentar añadir un factor de riesgo no válido >>";
              break;
            case 4:
              cout << "<< Error al intentar añadir un número de donaciones no válido >>";
              break;
          }
          cout << "\n\n";
          continuar();
          BORRAR;
          break;
        }
        NEGRITA; cout << "\nEl fichero ha sido cargado\n\n"; NORMAL;
        continuar();
        break;
      case 3:
        SUBRAYADO; cout << "\nNombre del fichero"; NORMAL; cout << " = ";
        getline(cin, cad);
        BORRAR;
        if(monticulo.grabarFichero(cad)){
          NEGRITA; cout << "\nFichero creado\n\n"; NORMAL;
        }else{
          NEGRITA; cout << "\nFichero no creado"; NORMAL;
          cout << "\n<< Error al crear el fichero >>\n\n";
        }
        continuar();
        break;
      case 4:
        cin >> d;
        monticulo.insertar(d);
        NEGRITA; cout << "\nEl donante ha sido añadido al montículo\n\n"; NORMAL;
        continuar();
        break;
      case 5:
        try{
          d=monticulo.cima();
          NEGRITA; cout << "La cima es: \n"; NORMAL;
          cout << d;
          cout << "\n";
        }catch(int i){
          NEGRITA; cout << "\nEl montículo está vacío\n\n"; NORMAL;
        }
        continuar();
        break;
      case 6:
        if (!monticulo.vacio()){
          error=false;
          do{
            if(error)
  						cout << "<< Número de donaciones incorrecto >>";
            SUBRAYADO; cout << "\n¿Cuantas donaciones se van a realizar?"; NORMAL; cout << " = ";
  					cin >> n;
  					cin.ignore(256,'\n');
  					error=true;
  					BORRAR;
          }while(n<0);
          for (int i=0;i<n;i++)
            monticulo.donar();
          NEGRITA; cout << "Donaciones realizadas\n\n";
          cout << "Ahora la cima es:\n\n"; NORMAL;
          cout << monticulo.cima();
          cout << "\n";
        }else{
          NEGRITA; cout << "\nEl montículo está vacío\n\n"; NORMAL;
        }
        continuar();
        break;
      case 7:
        if(monticulo.vacio()){
          NEGRITA; cout << "\nNo hay donantes almacenados\n\n"; NORMAL;
        }else{
          monticulo.borrar();
          NEGRITA; cout << "\nLa cima ha sido eliminada\n\n"; NORMAL;
        }
        continuar();
        break;
      case 8:
        monticulo.vaciar();
        NEGRITA; cout << "\nTodos los donantes han sido eliminados\n\n"; NORMAL;
        continuar();
        break;
      case 9:
        salir=true;
        break;
    }
  }while(!salir);
  return 0;
}
