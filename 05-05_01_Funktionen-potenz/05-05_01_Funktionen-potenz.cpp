#include <iostream>


/* Aufgabe 1: 
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe von zwei Zahlen auffordert. Das Programm soll daraufhin die Potenz der beiden Zahlen errechnen.
* Die Berechnung soll hierbei in einer eigenen Funktion stattfinden, die die beiden eingegebenen Zahlen vom Anwender als Parameter erwartet und das Ergebnis der Berechnung als Wert zurückgibt.
* Das Ergebnis der Berechnung soll dann auf den Bildschirm ausgeben werden.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

/*** FUNCTIONS ***/
int potenz(int Basis, int Exponent)              //Es gibt zwar die C++ Math-Funktion pow(), es soll aber das Schreiben eigener Funktionen geübt werden 
{
   int Potenzwert = 1;

   if (Exponent != 0)
   {
      for (int i=0; i<Exponent; ++i)             //Müsste genau genommen (d.h. für alle Zahlen) als konvergierende Reihe berechnet werden, es geht aber um das Einüben von Funktionen
      {                                          //...(und nicht um mathematische Feinheiten)
         Potenzwert = Potenzwert * Basis;
      }
   }
   return Potenzwert;
}

/*** PROGRAM STARTS HERE ***/
int main ()
{
   int Zahl1, Zahl2, Ergebnis;

   std::cout << "Geben Sie zwei positive, ganze Zahlen ein: " << std::endl;
   std::cout << "Zahl 1 (Basis): " << std::endl;
   std::cin >> Zahl1; //Basis
   std::cout << "Zahl 2 (Exponent): " << std::endl;
   std::cin >> Zahl2; //Exponent

   //Funktionsaufruf
   Ergebnis = potenz(Zahl1, Zahl2);


   //Ausgabe
   std::cout << "Der Potentzwert von " << Zahl1 << " hoch " << Zahl2 << " ist: " << Ergebnis << std::endl;
}

