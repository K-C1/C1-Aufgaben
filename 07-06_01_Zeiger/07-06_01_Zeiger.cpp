#include <iostream>


/* Aufgabe 1:
* Erstellen Sie eine C++-Anwendung, in der Sie dynamisch ein eindimensionales Array vom Typ short erstellen.
* Der Anwender Ihres Programms soll angeben können, aus wie vielen Elementen das Array bestehen soll.
* Legen Sie abwechselnd in alle Elemente des Arrays die Zahlen 0 und 1 hinein und geben Sie danach den Inhalt des Arrays auf den Bildschirm aus.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/


/*** FUNCTIONS ***/


/*** PROGRAM STARTS HERE ***/
int main()
{
   int Elemente;

   //Eingabe
   std::cout << "Geben Sie die Anzahl der Elemente im Array an: " << std::endl;
   std::cin >> Elemente;

   //Dynamische Speicherallokation
   short* NullEinsSchlange = new short[Elemente];

   //Array füllen
   for (int i = 0; i < Elemente; ++i)
   {
      NullEinsSchlange[i] = i%2;
   }

   //Ausgabe
   std::cout << "Array: ";
   for (int i = 0; i < Elemente; ++i)
   {
      std::cout << NullEinsSchlange[i];
   } 
   std::cout << std::endl;  

   //Speicherfreigabe
   delete[] NullEinsSchlange;
}





