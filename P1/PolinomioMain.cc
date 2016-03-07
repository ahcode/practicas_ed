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
  return 0;
}
