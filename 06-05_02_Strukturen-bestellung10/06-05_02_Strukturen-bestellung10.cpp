#include <iostream>
#include <string>

/* Aufgabe 2:
* Erweitern Sie die C++-Anwendung aus Aufgabe 1 dahingehend, dass der Anwender bis zu maximal zehn Bestellungen vornehmen kann,
* die jedoch alle an die gleiche Lieferanschrift gesendet und alle über die gleiche Kreditkarte abgerechnet werden.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/


/*** STRUCTS AND ENUMERATIONS ***/
enum land
{
   Deutschland, Oesterreich, Schweiz
};

struct lieferanschrift
{
   std::string Anrede;
   std::string Vorname;
   std::string Nachname;
   std::string Strasse;
   int Hausnummer;        //Da mit diesem Wert keine Berechnungen stattfinden, könnte auch der Datentyp std::string verwendet werden, es fiele aber die Plausibilitätsprüfung weg
   int Postleitzahl;      // dito (s.oben)
   std::string Ort;
   land Land;             
};

struct kreditkarte
{
   std::string Kreditkartennummer;
   std::string Datum;
};

struct bestellung
{
   lieferanschrift Adresse;
   kreditkarte Bezahlkarte;
   std::string Ware[10];
};

/*** FUNCTIONS ***/
//leer

/*** PROGRAM STARTS HERE ***/
int main()
{
   bestellung Bestellung10;
   std::string Eingabe_Land;
   int WareAnzahl = sizeof(Bestellung10.Ware)/sizeof(Bestellung10.Ware[0]);
   char MehrBestellen;

   //Eingabe Ware
   std::cout << "Geben Sie die gewünschte Ware ein: " << std::endl;

   int Artikel = 0;
   while (Artikel < WareAnzahl)
   {
      std::cout << "Artikel : " << Artikel+1 << std::endl;
      std::cin >> Bestellung10.Ware[Artikel];

      if (Artikel < WareAnzahl-1)
      {
         std::cout << "Weitere Artikel bestellen? (y/n)" << std::endl;
         std::cin >> MehrBestellen;
         if (MehrBestellen == 'y')
            ++Artikel;
         else
            break;
      }
      else
         break;
   }

   //Eingabe Lieferadresse
   std::cout << "Geben Sie die Lieferadresse ein: " << std::endl;
   std::cout << " Anrede: " << std::endl;
   std::cin >> Bestellung10.Adresse.Anrede;
   std::cout << " Vorname: " << std::endl;
   std::cin >> Bestellung10.Adresse.Vorname;
   std::cout << " Nachnae: " << std::endl;
   std::cin >> Bestellung10.Adresse.Nachname;
   std::cout << " Strasse: " << std::endl;
   std::cin >> Bestellung10.Adresse.Strasse;
   std::cout << " Hausnummer: " << std::endl;
   std::cin >> Bestellung10.Adresse.Hausnummer;
   std::cout << " Postleitzahl: " << std::endl;
   std::cin >> Bestellung10.Adresse.Postleitzahl;
   std::cout << " Ort: " << std::endl;
   std::cin >> Bestellung10.Adresse.Ort;
   std::cout << " Land (Deutschland, Oesterreich, Schweiz): " << std::endl;
   std::cin >> Eingabe_Land;

   //Überprüfe Land (3x)
   int counter=3;
   while (true)
   {
      if (Eingabe_Land == "Deutschland") {
         Bestellung10.Adresse.Land = Deutschland; 
         break;
      }
      else if (Eingabe_Land == "Oesterreich")
      {
         Bestellung10.Adresse.Land = Oesterreich; 
         break;
      }
      else if (Eingabe_Land == "Schweiz")
      {
         Bestellung10.Adresse.Land = Schweiz;
         break; 
      }
      else
      {
         if ( counter == 0)
            return 0;                                                                           //Programmabbruch bei 3x falscher Eingabe
         else
         {
            std::cout << "Die Eingabe ist leider ungültig, bitte geben Sie Deutschland, Oesterreich oder Schweiz ein. Noch " << counter << " Versuch(e), Danke." << std::endl;    
            std::cin >> Eingabe_Land;
            --counter;
         }
      }
   }

   //Eingabe Kreditkartendaten
   std::cout << "Geben Sie die Kreditkartennummer ein: " << std::endl;
   std::cin >> Bestellung10.Bezahlkarte.Kreditkartennummer;
   std::cout << "Geben Sie das Gültigkeitsdatum der Kreditkarte ein: " << std::endl;
   std::cin >> Bestellung10.Bezahlkarte.Datum;

   //Ausgabe - Test
   std::cout << std::endl;
   std::cout << "Sie haben bestellt: " << std::endl;
   for(int j = 0; j < WareAnzahl; ++j)
   {
      std::cout << "Artikel " << j+1 << " : " << Bestellung10.Ware[j] << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Anrede: " << Bestellung10.Adresse.Anrede << std::endl;
   std::cout << "Vorname: " << Bestellung10.Adresse.Vorname << std::endl;
   std::cout << "Nachname: " << Bestellung10.Adresse.Nachname << std::endl;
   std::cout << "Strasse: " << Bestellung10.Adresse.Strasse << std::endl;
   std::cout << "Hausnummer: " << Bestellung10.Adresse.Hausnummer << std::endl;
   std::cout << "Postleitzahl: " << Bestellung10.Adresse.Postleitzahl << std::endl;
   std::cout << "Ort: " << Bestellung10.Adresse.Ort << std::endl;
   std::cout << "Land: " << Bestellung10.Adresse.Land << std::endl;                            //Die Ausgabe erfolgt hier als int-Wert 
   std::cout << std::endl;
   std::cout << "Kreditkartennummer: " << Bestellung10.Bezahlkarte.Kreditkartennummer << std::endl;
   std::cout << "Gültigkeitsdatum: " << Bestellung10.Bezahlkarte.Datum << std::endl;
   std::cout << std::endl;

}

