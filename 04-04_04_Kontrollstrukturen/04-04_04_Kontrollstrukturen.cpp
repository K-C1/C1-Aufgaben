#include <iostream>

/* Aufgabe 4:
* Entwickeln Sie eine C++-Anwendung, die die kleinste und größte Zahl von vier vorgegebenen Zahlen ermittelt, die in einem Array vom Typ int gespeichert sind.
* Das Programm soll auf den Bildschirm die größte und die kleinste Zahl aus dem Array ausgeben.
* Testen Sie Ihr Programm, indem Sie im Array verschiedene Zahlen speichern und die größte und kleinste Zahl sich jeweils an verschiedenen Stellen im Array befindet.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

int main()
{
   //Variante 1 - Array fest (Beispiele)
//   int a [4] = { 12, 24, 48, 64 };
//   int a [4] = { 234, 877, 12, -5 };
   int a [4] = { -56, 32, -98, 7 };
//   int a [4] = {1023, -7, 34, 5};
//   int a [4] = {2, 2, 2, 2};

   //Variante 2 - Array eingeben
// /*
   std::cout << "Geben Sie vier ganze Zahlen ein: " << std::endl;

   for (int j = 0; j < 4; ++j)
   {
      std::cout << "Zahl " << j+1 << ": " << std::endl;
      std::cin >> a[j];   
   }
// */

   //Ermitteln der grössten und der kleinsten Zahl im Array
   int g = a[0];
   int k = a[0];

   for (int i = 1; i < 4; ++i)
   {
      if (k >= a[i])
      {
         k = a[i];
      }
      else if (g <= a[i])
      {
         g = a[i];
      }
   }
   
   //Ausgabe
   std::cout << "Die kleinste Zahl ist: " << k << std::endl;
   std::cout << "Die grösste Zahl ist: " << g << std::endl;
 
}
