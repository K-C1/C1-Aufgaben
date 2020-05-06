#include <iostream>

/* Aufgabe 3:
* Entwickeln Sie ein C++-Programm, das nach Eingabe zweier Stadtnamen die Entfernung zwischen den beiden Städten in Kilometer ausgibt.
* Verwenden Sie folgende Daten, um Ihr Programm testen zu können:
* Die Entfernung zwischen Köln und München beträgt 480 Kilometer, zwischen München und Berlin 530 Kilometer und zwischen Berlin und Köln 500 Kilometer.
* Die Entfernung soll unabhängig von der Reihenfolge der Eingabe der Stadtnamen ausgegeben werden.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

// Variante 2 - Beliebige Anzahl Städte


/*** FUNCTIONS ***/
int getStadtPosition(std::string SuchText, std::string FindText[], int max)
{
    for (int j=0; j<max; ++j)
    {
        if (SuchText == FindText[j])  //Eingelesene Stadt == hinterlegte Stadt
        {
           return j;                  //Position der im Array Orte gefundenen Stadt
        }
    }

    std::cout << "ERROR: Die Stadt " << SuchText << " konnte nicht gefunden werden." << std::endl;
    exit (0);                         //Programmabbruch
}


/*** PROGRAM STARTS HERE ***/
int main()
{
   int AnzahlEingaben = 2;                      //Anzahl der Städte, die vom Nutzer maximal eingegeben werden können
   std::string StadtName;
   int StadtPosition[AnzahlEingaben];
   int Strecke = 0;

   //Array Orte der Form:
   // +-----+-----+-----+
   // |  0  |  1  |  2  | Index = Position
   // +-----+-----+-----+
   // |  B  |  K  |  M  | Wert = Stadt
   // +-----+-----+-----+
   std::string Orte[] = {"Berlin","Koeln","Muenchen"};
   int AnzahlOrte = sizeof(Orte)/sizeof(Orte[0]);
  

   //Array Distanzen der Form:
   // +-----+-----+-----+-----+
   // |     |  B  |  K  |  M  |
   // +-----+-----+-----+-----+
   // |  B  |  0  | 500 | 530 |  Index 0..2
   // +-----+-----+-----+-----+ 
   // |  K  | 500 |  0  | 480 |  Index 3..5
   // +-----+-----+-----+-----+
   // |  M  | 530 | 480 |  0  |  Index 6..8
   // +-----+-----+-----+-----+                 -> Distanz-Index der gesuchten Städte ergibt sich aus 3*Stadt1-Index (d.h. Zeile) + Stadt2-Index (d.h. Spalte in der Zeile)
   int Distanzen[] = 
      {
      	0,500,530,
      	500,0,480,
      	530,480,0
      };


   //Eingabe
   std::cout << "Geben Sie " << AnzahlEingaben << " Städtenamen ein (Berlin, Koeln, Muenchen)." << std::endl;

   for (int i = 0; i < AnzahlEingaben; ++i)
   {
       std::cout << "Stadt " << i+1 << ": " << std::endl;
       std::cin >> StadtName;

   //Suche nach der eingegebenen Stadt im hinterlegten Array Orte                                           
   	   StadtPosition[i] = getStadtPosition(StadtName, Orte, AnzahlOrte);           //Umwandlung in Position (d.h. Index im hinterlegten Array Orte)
   }

   //Ermitteln der gesuchten (Teil-)Strecken im hinterlegten Array Distanzen und der Gesamtstrecke
   for (int j = 0; j < AnzahlEingaben-1; ++j)
   {
       Strecke = Strecke + Distanzen[StadtPosition[j]*AnzahlOrte + StadtPosition[j+1]];
   }

   //Ausgabe
   std::cout << "Die Entfernung zwischen den Städten beträgt "  << Strecke << " Kilometer." << std::endl;
}