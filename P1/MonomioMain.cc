#include <iostream>
#include "Monomio.h"

using std::cout;
using std::cin;

int main(){
    float c;
    int g;
    cout << "\nPrimer monomio:\n";
    cout << "\tCoeficiente = ";
    cin >> c;
    cout << "\tGrado = ";
    cin >> g;
    Monomio m1(c,g);
    cout << "\t" << m1 << "\n\n";
    cout << "Segundo monomio:\n";
    cout << "\tCopia del primer monomio (Constructor de copia)\n";
    Monomio m2(m1);
    cout << "\t" << m2 << "\n\n";
    cout << "Tercer monomio:\n";
    cout << "\tValores por defecto\n";
    Monomio m3;
    cout << "\t" << m3 << "\n\n";

    //Menú
    int op, n1, n2, n3;
    float x;
    Monomio *m[3]={&m1, &m2, &m3};
    bool salir = false;
    while (salir==false){
      do{
        cout << "1. Imprimir monomios\n";
        cout << "2. Valor de un monomio\n";
        cout << "3. Producto de dos monomios\n";
        cout << "4. Salir\n";
        cout << "\nOpción = ";
        cin >> op;
        cout << "\n";
      }while(op<1 || op>4);

      switch(op){
        case 1:
          cout << "M1: " << m1 << "\n";
          cout << "M2: " << m2 << "\n";
          cout << "M3: " << m3 << "\n\n";
          break;
        case 2:
          do{
            cout << "Introduce el número de monomio = ";
            cin >> n1;
          }while(n1<1 || n1>3);
          n1--;
          cout << "Introduce valor de X = ";
          cin >> x;
          cout << "M" << n1 << ": " << m[n1]->valor(x) << "\n\n";
          break;
        case 3:
          do{
            cout << "Introduce el número del primer monomio a multiplicar = ";
            cin >> n1;
          }while(n1<1 || n1>3);
          n1--;
          do{
            cout << "Introduce el número del segundo monomio a multiplicar = ";
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

          *(m[n3])=*(m[n1])*(*(m[n2]));
          cout << "M" << n3+1 << ": " << *(m[n3]) << "\n\n";
          break;
        case 4:
          salir=true;
          break;
      }
    }
    return 0;
}
