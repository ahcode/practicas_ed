#include <iostream>
#include "Donante.hpp"
#include "macros.hpp"

using namespace ed;
using std::cout;
using std::cin;


int main(){
	BORRAR;
	Donante d[3];
	NEGRITA; cout << "Donante 1:\n"; NORMAL;
  cin >> d[0];
	BORRAR;
	NEGRITA; cout << "Donante 1:\n"; NORMAL;
  cout << d[0] << "\n";
	NEGRITA; cout << "Donante 2:\n"; NORMAL;
  cout << "\tCopia del primer donante (Constructor de copia)\n";
  d[1]=d[0];
  cout << d[1] << "\n";
	NEGRITA; cout << "Donante 3:\n"; NORMAL;
  cout << "\tValores por defecto\n";
  cout << d[2] << "\n";
	INVERSO; cout << "Presiona enter para continuar..."; NORMAL;
	getchar();
	BORRAR;

	int op, n, n2, i;
	bool salir = false, error;
	while (salir==false){
		error=0;
		do{
			NEGRITA; cout << "1."; NORMAL; cout << " Leer Donante\n";
			NEGRITA; cout << "2."; NORMAL; cout << " Mostrar Donante\n";
			NEGRITA; cout << "3."; NORMAL; cout << " Modificar Donante\n";
			NEGRITA; cout << "4."; NORMAL; cout << " Comparar dos donantes\n";
			NEGRITA; cout << "5."; NORMAL; cout << " Salir\n\n";
			if(error)
				cout << "<< La opción introducida no es válida >>";
			SUBRAYADO; cout << "\nOpción"; NORMAL; cout << " = ";
			cin >> op;
			cout << "\n";
			BORRAR;
			error++;
		}while(op<1 || op>5);

		switch(op){
			case 1:
				error=false;
				do{
					for (i=0;i<3;i++){
						NEGRITA; cout << "Donante " << i+1; NORMAL; cout << ":\n" << d[i] << "\n";
					}
					if(error)
						cout << "<< El donante introducido no es válido >>";
					SUBRAYADO; cout << "\n¿Que donante quieres cambiar?"; NORMAL; cout << " = ";
					cin >> n;
					cin.ignore(256,'\n');
					error=true;
					BORRAR;
				}while(n<1 || n>3);
				NEGRITA; cout << "Donante " << n << ":\n"; NORMAL;
				cin >> d[n-1];
				BORRAR;
				break;
			case 2:
				error=false;
				do{
					if(error)
						cout << "<< El donante introducido no es válido >>";
					SUBRAYADO; cout << "\n¿Que donante quieres mostrar?"; NORMAL; cout << " = ";
					cin >> n;
					error=true;
					BORRAR;
				}while(n<1 || n>3);
				NEGRITA; cout << "Donante " << n << ":\n"; NORMAL;
				cout << d[n-1] << "\n";
				INVERSO; cout << "Presiona enter para continuar..."; NORMAL;
				cin.ignore(256,'\n');
				getchar();
				BORRAR;
				break;
			case 3:
				error=false;
				do{
					for (i=0;i<3;i++){
						NEGRITA; cout << "Donante " << i+1; NORMAL; cout << ":\n" << d[i] << "\n";
					}
					if(error)
						cout << "<< El donante introducido no es válido >>";
					SUBRAYADO; cout << "\n¿Que donante quieres modificar?"; NORMAL; cout << " = ";
					cin >> n;
					error=true;
					BORRAR;
				}while(n<1 || n>3);
				d[n-1].modificarDonante();
				break;
			case 4:
				for (i=0;i<3;i++)
					cout << "Donante " << i+1 << ":\n" << d[i] << "\n";
				error=false;
				do{
					if(error)
						cout << "<< El donante introducido no es válido >>\n";
					cout << "Primer donante a comparar: ";
					cin >> n;
					error=true;
				}while(n<1 || n>3);
				error=false;
				do{
					if(error)
						cout << "<< El donante introducido no es válido >>\n";
					cout << "Segundo donante a comparar: ";
					cin >> n2;
					error=true;
				}while(n2<1 || n2>3);
				BORRAR; NEGRITA;
				if(d[n-1]==d[n2-1]){
					cout << "\nLos donantes son iguales\n\n";
				}else if(d[n-1]<=d[n2-1]){
					cout << "\nEl donante " << n << " es anterior al donante " << n2 << " lexicográficamente\n\n";
				}else{
					cout << "\nEl donante " << n << " es posterior al donante " << n2 << " lexicográficamente\n\n";
				}
				NORMAL;
				INVERSO; cout << "Presiona enter para continuar..."; NORMAL;
				cin.ignore(256,'\n');
				getchar();
				BORRAR;
				break;
			case 5:
				salir=true;
				break;
		}
	}
	return 0;
}
