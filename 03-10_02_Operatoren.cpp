#include <iostream>

int main()
{
   int a, a2, b, b2, b3;
   int t, h, z, e;

   std::cout << "Geben Sie eine vierstellige Zahl ein: " << std::endl;

   //Einlesen a
   std::cin >> a;
   a2 = a;           //Hilfsvariable für Varianten 2 und 3


   //Variante 1 - Kalkulation: Quersumme b (simpel)
   t = a / 1000;
   a = a%1000;

   h = a / 100;
   a = a%100;

   z = a / 10;
   e = a%10;

   b = t + h + z + e;


   //Variante 2 - Kalkulation: Quersumme b2 (zwei Variablen)
   a = a2;
   b2 = a / 1000;
   a = a%1000;

   b2 = b2 + a / 100;  //Punkt vor Strich
   a = a%100;

   b2 = b2 + a / 10;
   e = a%10;

   b2 = b2 + e;


   //Variante 3 - Kalkulation: Quersumme b3   <-- Könnte auch eleganter über eine while-Schleife gelöst werden, aber es geht hier ja um die Operatoren
   a = a2;
   b3 = 0;

   b3 = b3 + a%10;         //Addiere die Einer
   a = a / 10;             //Shift um eine Dezimalstelle nach rechts

   b3 = b3 + a%10;         //Addiere die Zehner
   a = a / 10;

   b3 = b3 + a%10;         //Addiere die Hunderter
   a = a / 10;

   b3 = b3 + a%10;         //Addiere die Tausender


   //Ausgabe
   std::cout << "Die Quersumme ist: " << b << std::endl;
   std::cout << "...was das selbe ist wie: " << b2 << std::endl;
   std::cout << "...und wie: " << b3 << std::endl;
}
