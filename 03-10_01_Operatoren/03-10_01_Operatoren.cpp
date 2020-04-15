#include <iostream>

/* Aufgabe 1:  
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe von drei Zahlen auffordert.
* Das Programm soll den Wert 10 zur ersten eingegebenen Zahl hinzuaddieren, das Ergebnis mit der zweiten eingegebenen Zahl multiplizieren und dann durch die dritte eingegebene Zahl dividieren.
* Die Berechnung soll hierbei innerhalb einer einzigen Code-Zeile erfolgen. Das Ergebnis soll auf den Bildschirm ausgegeben werden.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

int main()
{
   double a, b, c, d;

   std::cout << "Geben Sie drei Zahlen ein: " << std::endl;

   //Einlesen a
   std::cout << "Erste Zahl: " << std::endl;
   std::cin >> a;

   //Einlesen b
   std::cout << "Zweite Zahl: " << std::endl;
   std::cin >> b;

   //Einlesen c
   std::cout << "Dritte Zahl: " << std::endl;
   std::cin >> c;

   //Kalkulation d: a -> +10 -> *b -> /c
   d = (a + 10) * b / c;

   //Ausgabe
   std::cout << "Das Ergebnis lautet: " << d << std::endl;
}
