#include <iostream>

// Aufgabe 2:
// Erweitern Sie das Programm aus Aufgabe 1 derart, dass die Quersummer einer beliebigen Zahl errechnet wird.

// (Lösung ist Variante 2 aus Aufgabe 1)

int main()
{
   int a, b;

   std::cout << "Geben Sie eine vierstellige Zahl ein: " << std::endl;

   std::cin >> a;
   b = 0;

   while (a != 0)
   {
      b = b + a%10;       //Bilde Quersumme
      a = a / 10;         //Shift um eine Dezimalstelle nach rechts
   }

   //Ausgabe
   std::cout << "Die Quersumme ist: " << b << std::endl;
}

