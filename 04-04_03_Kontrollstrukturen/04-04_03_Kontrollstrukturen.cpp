#include <iostream>
#include <math.h>

/* Aufgabe 3:
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe einer Zahl auffordert. Das Programm soll daraufhin errechnen, ob es sich um eine Primzahl handelt.
* Ist dies der Fall, soll eine entsprechende Meldung auf den Bildschirm ausgegeben werden. Andernfalls soll die Meldung ausgegeben werden, dass es sich um keine Primzahl handelt.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

int main()
{
   int a, S;
   bool P = true;

   std::cout << "Geben Sie eine ganzzahlige Zahl ein: " << std::endl;
   std::cin >> a;

   if (a <= 1)              //Eine Primszahl ist grösser als 1 (und nur durch 1 und sich selbst teilbar)
   {
      P = false;
   }
   else if (a > 2)         //2 ist eine Primzahl; dies wird durch das Abrunden der Schranke aber sowieso nicht geprüft, die else-if-Bedingung könnte also als else umgesetzt werden    
   {
      //Ansatz: Jede Zahl kann in Primzahlen zerlegt werden, wovon mindestens ein Teiler kleiner der Wurzel aus der Zahl (Schranke) sein muss
      //        Wird also bis zur Schranke kein Teiler gefunden, kann es sich nur selbst um eine Primzahl handeln
      S = sqrt(a);        //Definition der oberen Schranke; es interessieren uns nur die ganzzahligen Werte der Wurzel von a
      for (int i = 2; i <= S; ++i) 
      {
         if (a%i == 0)
         { 
            P = false;    //Wird ein Teiler (hier: der kleinste) gefunden, ist es keine Primzahl  
            break;        //...und die Suche kann abgebrochen werden
         }   
      }
   }

   //Ausgabe
   if (P)
   {
      std::cout << "Die Zahl " << a << " ist eine Primzahl." << std::endl;
   }
   else
   {
      std::cout << "Die Zahl " << a << " ist keine Primzahl." << std::endl;   
   }
}
