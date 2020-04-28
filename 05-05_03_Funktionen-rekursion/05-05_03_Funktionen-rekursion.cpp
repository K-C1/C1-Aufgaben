#include <iostream>

/* Aufgabe 3:
* Für Experten: Schreiben Sie Ihre Lösung zur Aufgabe 2 so um, dass die Umkehrung der Ziffernreihenfolge durch Rekursion stattfindet.
* Rekursion bedeutet, dass Anweisungen nicht innerhalb einer Schleife wiederholt ausgeführt werden, sondern dass eine Funktion sich wiederholt selbst aufruft.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/


/*** FUNCTIONS ***/
void umdrehen_rekursiv(unsigned int &Zahl, unsigned int Umdrehen = 0)
{
   if (Zahl > 0)
   {
      Umdrehen = Umdrehen*10 + Zahl%10;    //Umrechnung hier ist nötig, da Zahl referenziert ist, denn ....
      Zahl = Zahl/10;  

      umdrehen_rekursiv(Zahl, Umdrehen);   //...ohne Referenzvariable könnte der rekursive Funktionsaufruf lauten: umdrehen_rekursiv(Zahl/10, Umdrehen*10 + Zahl%10);
   }
   else                                    //Abbruchbedingung erfüllt (Zahl ist: 0)
   {
      Zahl = Umdrehen;                     
   } 
}


/*** PROGRAM STARTS HERE ***/
int main()
{
   unsigned int Wert;

   //Eingabe
   std::cout << "Geben Sie eine mehrstellige, ganze und positive Zahl ein: " << std::endl;
   std::cin >> Wert;

   //Funktionsaufruf
   umdrehen_rekursiv(Wert);

   //Ausgabe
   std::cout << "Die eingegebene Zahl lautet umgedreht: " << Wert << std::endl;
}

