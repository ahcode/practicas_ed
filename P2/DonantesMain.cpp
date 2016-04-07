#include <iostream>
#include "Donantes.hpp"
#include "macros.hpp"

using namespace ed;
using std::cout;
using std::cin;

void continuar(){
  INVERSO; cout << "Presiona enter para continuar..."; NORMAL;
	getchar();
	BORRAR;
}

int main(){
  BORRAR;
  Donantes donantes;
  Donante d;
  int op, n;
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
      NEGRITA; cout << "9."; NORMAL; cout << " Vaciar la lista\n";
			NEGRITA; cout << "10."; NORMAL; cout << " Salir\n\n";
      if(error)
				cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
			cin >> op;
      cin.ignore(256,'\n');
			BORRAR;
			error=true;
    }while(op<1 || op>10);

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
        break;
      case 4:
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
        donantes.borrarLista();
        NEGRITA; cout << "\nTodos los donantes han sido eliminados\n\n"; NORMAL;
        continuar();
        break;
      case 10:
        salir=true;
        break;
    }
  }while(!salir);
}
