#include <iostream>


/* Aufgabe 2: 
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe einer Zahl auffordert.
* Das Programm soll daraufhin die Reihenfolge der Ziffern in der Zahl umdrehen - beispielsweise soll 1234 in 4321 umgewandelt werden.
* Das Umdrehen der Reihenfolge der Ziffern soll in einer eigenen Funktion erfolgen, die keinen Rückgabewert besitzt und einen Parameter erwartet.
* Die Ausgabe der umgedrehten Zahl auf den Bildschirm soll in der Funktion main() erfolgen.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

/*** FUNCTIONS ***/
void umdrehen(unsigned int &Zahl)
{
   unsigned int u = Zahl;   //Hilfsvariable für schrittweisen Abbau der eingegebenen Zahl
   unsigned int v = 0;      //Hilfsvariable für Zusammensetzen der umgedrehten Zahl

   while(u > 0)
   {
      v = v*10 + u%10;
      u = u / 10;
   }
   Zahl = v;                //Da Zahl referenziert ist, wird aus Effizienzgründen erst hier an die Zahl zurück übergeben, 
}                           //...es könnte aber auch direkt mit Zahl gearbeitet werden (in diesem Fall alle v durch Zahl ersetzen)

/*** PROGRAM STARTS HERE ***/
int main()
{
   unsigned int Wert;

   //Eingabe
   std::cout << "Geben Sie eine mehrstellige, ganze und positive Zahl ein: " << std::endl;
   std::cin >> Wert;

   //Funktionsaufruf
   umdrehen(Wert);

   //Ausgabe
   std::cout << "Die eingegebene Zahl lautet umgedreht: " <<  Wert << std::endl;
}

