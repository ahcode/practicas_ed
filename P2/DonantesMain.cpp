/*!
\file DonantesMain.cpp
\brief Programa principal para probar la clase Donantes
\author Álvaro Herrero Pérez
\date 11/04/2016
*/

/*!
\mainpage Práctica 2 de la asignatura Estructura de Datos
\author Álvaro Herrero Pérez
\date 11 de Abril de 2016
*/

#include <iostream>
#include <string>
#include "Donantes.hpp"
#include "macros.hpp"
#include "ficherosDonantes.hpp"

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
  Donantes donantes;
  Donante d;
  int op, n;
  std::string cad, cad2;
  bool error, salir=false;
  do{
    error=0;
    do{
      NEGRITA; cout << "1."; NORMAL; cout << " Comprobar si hay donantes\n";
      NEGRITA; cout << "2."; NORMAL; cout << " Cargar donantes por teclado\n";
			NEGRITA; cout << "3."; NORMAL; cout << " Cargar donantes desde fichero\n";
			NEGRITA; cout << "4."; NORMAL; cout << " Grabar donantes en fichero\n";
			NEGRITA; cout << "5."; NORMAL; cout << " Insertar donante\n";
      NEGRITA; cout << "6."; NORMAL; cout << " Modificar donante\n";
      NEGRITA; cout << "7."; NORMAL; cout << " Borrar donante\n";
      NEGRITA; cout << "8."; NORMAL; cout << " Mostrar donantes\n";
      NEGRITA; cout << "9."; NORMAL; cout << " Buscar un donante\n";
      NEGRITA; cout << "10."; NORMAL; cout << " Vaciar la lista\n";
			NEGRITA; cout << "11."; NORMAL; cout << " Salir\n\n";
      if(error)
				cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
			cin >> op;
      cin.ignore(256,'\n');
			BORRAR;
			error=true;
    }while(op<1 || op>11);

    switch(op){
      case 1:
        if(donantes.hayDonantes()){
          NEGRITA; cout << "\nHay donantes almacenados\n\n"; NORMAL;
        }else{
          NEGRITA; cout << "\nNo hay donantes almacenados\n\n"; NORMAL;
        }
        continuar();
        break;
      case 2:
        donantes.leerDonantes();
        break;
      case 3:
        SUBRAYADO; cout << "\nNombre del fichero"; NORMAL; cout << " = ";
        getline(cin, cad);
        BORRAR;
        try{
          donantes=cargarFichero(cad);
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
          }
          cout << "\n\n";
          continuar();
          BORRAR;
          break;
        }
        NEGRITA; cout << "\nEl fichero ha sido cargado\n\n"; NORMAL;
        continuar();
        BORRAR;
        break;
      case 4:
        SUBRAYADO; cout << "\nNombre del fichero"; NORMAL; cout << " = ";
        getline(cin, cad);
        BORRAR;
        if(grabarFichero(cad,donantes)){
          NEGRITA; cout << "\nFichero creado\n\n"; NORMAL;
        }else{
          NEGRITA; cout << "\nFichero no creado"; NORMAL;
          cout << "\n<< Error al crear el fichero >>\n\n";
        }
        continuar();
        BORRAR;
        break;
      case 5:
        d.leerDonante();
        donantes.insertarDonante(d);
        BORRAR;
        break;
      case 6:
        error=false;
        do{
          donantes.escribirDonantes();
          if(error)
						cout << "<< El donante introducido no es válido >>";
          SUBRAYADO; cout << "\n\n¿Que donante quieres modificar?"; NORMAL; cout << " = ";
					cin >> n;
					cin.ignore(256,'\n');
					error=true;
					BORRAR;
        }while(n<1 || n>donantes.numDonantes());
        d=donantes.getDonante(n);
        donantes.borrarDonante(n);
        d.modificarDonante();
        donantes.insertarDonante(d);
        BORRAR;
        break;
      case 7:
        error=false;
        if(donantes.hayDonantes()){
          do{
            donantes.escribirDonantes();
            if(error)
  						cout << "<< El donante introducido no es válido >>";
            SUBRAYADO; cout << "\n\n¿Que donante quieres eliminar?"; NORMAL; cout << " = ";
            cin >> n;
            cin.ignore(256,'\n');
            error=true;
            BORRAR;
          }while(n<1 || n>donantes.numDonantes());
          donantes.borrarDonante(n);
        }else{
          NEGRITA; cout << "\nNo hay donantes almacenados\n\n"; NORMAL;
          continuar();
          BORRAR;
        }
        break;
      case 8:
        donantes.escribirDonantes();
        cout << "\n";
        continuar();
        break;
      case 9:
        SUBRAYADO; cout << "\nNombre del donante"; NORMAL; cout << " = ";
        getline(cin,cad);
        BORRAR;
        SUBRAYADO; cout << "\nApellidos del donante"; NORMAL; cout << " = ";
        getline(cin,cad2);
        BORRAR;
        try{
          d=donantes.buscarDonante(cad,cad2);
          NEGRITA; cout << "\nDonante encontrado!\n\n"; NORMAL;
          cout << d << "\n";
        }catch(int i){
          NEGRITA; cout << "\nDonante no encontrado\n\n"; NORMAL;
        }
        continuar();
        break;
      case 10:
        donantes.borrarLista();
        NEGRITA; cout << "\nTodos los donantes han sido eliminados\n\n"; NORMAL;
        continuar();
        break;
      case 11:
        salir=true;
        break;
    }
  }while(!salir);
}
