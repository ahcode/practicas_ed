#include <iostream>
#include "Polinomio.h"

using std::cout;
using std::cin;

int main(){
  Polinomio p1;
  cout << "\nPRIMER POLINOMIO:\n";
  cin >> p1;
  cout << "\t" << p1 << "\n\n";
  cout << "SEGUNDO POLINOMIO:\n";
  cout << "\tCopia del primer polinomio (Constructor de copia)\n";
  Polinomio p2(p1);
  cout << "\t" << p2 << "\n\n";
  cout << "TERCER POLINOMIO:\n";
  cout << "\tValores por defecto\n";
  Polinomio p3;
  cout << "\t" << p3 << "\n\n";

  //Menú
  int op, n1, n2, n3;
  float x;
  Polinomio *p[3]={&p1, &p2, &p3};
  bool salir = false;
  while (salir==false){
    do{
      cout << "1. Valor de un polinomio\n";
      cout << "2. Suma de dos polinomios\n";
      cout << "3. Producto de dos polinomios\n";
      cout << "4. Modificar un polinomio (>>)\n";
      cout << "5. Mostrar un polinomio (<<)\n";
      cout << "6. Salir\n";
      cout << "\nOpción = ";
      cin >> op;
      cout << "\n";
    }while(op<1 || op>6);

    switch(op){
      case 1:
        do{
          cout << "Introduce el número de polinomio = ";
          cin >> n1;
        }while(n1<1 || n1>3);
        cout << "Introduce valor de X = ";
        cin >> x;
        cout << "P" << n1 << ": " << p[n1-1]->valor(x) << "\n\n";
        break;
      case 2:
        do{
          cout << "Introduce el número del primer polinomio a sumar = ";
          cin >> n1;
        }while(n1<1 || n1>3);
        n1--;
        do{
          cout << "Introduce el número del segundo polinomio a sumar = ";
          cin >> n2;
        }while(n2<1 || n2>3 || n1==n2);
        n2--;

        if ((n1==0 && n2==1)||(n1==1 && n2==0)){
          n3=2;
        }else{
          if ((n1==1 && n2==2)||(n1==2 && n2==1)){
            n3=0;
          }else{
            if ((n1==0 && n2==2)||(n1==2 && n2==0)){
              n3=1;
            }
          }
        }

        *(p[n3])=*(p[n1])+(*(p[n2]));
        cout << "P" << n3+1 << ": " << *(p[n3]) << "\n\n";
        break;
      case 3:
        do{
          cout << "Introduce el número del primer polinomio a multiplicar = ";
          cin >> n1;
        }while(n1<1 || n1>3);
        n1--;
        do{
          cout << "Introduce el número del segundo polinomio a multiplicar = ";
          cin >> n2;
        }while(n2<1 || n2>3 || n1==n2);
        n2--;

        if ((n1==0 && n2==1)||(n1==1 && n2==0)){
          n3=2;
        }else{
          if ((n1==1 && n2==2)||(n1==2 && n2==1)){
            n3=0;
          }else{
            if ((n1==0 && n2==2)||(n1==2 && n2==0)){
              n3=1;
            }
          }
        }

        *(p[n3])=*(p[n1])*(*(p[n2]));
        cout << "P" << n3+1 << ": " << *(p[n3]) << "\n\n";
        break;
      case 4:
        do{
          std::cout << "Número de monomio a modificar = ";
          std::cin >> n1;
        }while(n1<1 || n1>3);
        std::cin >> *(p[n1-1]);
        std::cout << "\n";
        break;
      case 5:
        do{
          std::cout << "Número de monomio a mostrar = ";
          std::cin >> n1;
        }while(n1<1 || n1>3);
        std::cout << *(p[n1-1]) << "\n\n";
        break;
      case 6:
        salir=true;
        break;
    }
  }
  return 0;
}
