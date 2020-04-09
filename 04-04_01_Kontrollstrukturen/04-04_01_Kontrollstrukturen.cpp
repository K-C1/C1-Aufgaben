#include <iostream>

/* Aufgabe 1:
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe einer vierstelligen Zahl auffordert.
* Das Programm soll daraufhin die Quersumme der Zahl mit Hilfe einer Schleife errechnen und das Ergebnis dann auf den Bildschirm ausgeben.
*/

int main()
{
   int a, a2, b, b2;

   std::cout << "Geben Sie eine vierstellige Zahl ein: " << std::endl;

   std::cin >> a;
   a2 = a;            //Hilfsvariable für Variante 2

   //Variante 1 - Anzahl Stellen bekannt (i = 4)
   b = 0;

   for (int i = 4; i > 0; --i)
   {
      b = b + a%10;
      a = a / 10;
   }


   //Variante 2 - Anzahl Stellen beliebig
   a = a2;
   b2 = 0;

   while (a != 0)
   {
      b2 = b2 + a%10;       //Bilde Quersumme
      a = a / 10;           //Shift um eine Dezimalstelle nach rechts
   }

   //Ausgabe
   std::cout << "Die Quersumme ist: " << b << std::endl;
   std::cout << "...was das selbe ist wie (bei vierstelliger Zahl): " << b2 << std::endl;

}

