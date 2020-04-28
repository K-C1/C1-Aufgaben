#include <iostream>
#include <string>

/* Aufgabe 1:
* Entwickeln Sie eine C++-Anwendung, die den Anwender zur Eingabe einer Bestellung auffordert.
* Der Anwender muss hierbei der Reihe nach die bestellte Ware, die Lieferanschrift, die Kreditkartennummer und das Gültigkeitsdatum der Kreditkarte eingeben.
* Die Daten sollen hierbei in geeigneten Variablen unter Zuhilfenahme benutzerdefinierter Strukturen und Enumerationen gespeichert werden.
* Lieferanschrift und Kreditkartendaten sollen jeweils in einer eigenen Struktur gespeichert werden. 
* Die Bestellung wird ebenfalls in einer eigenen Struktur gespeichert, die sich der anderen beiden Strukturen bedient.
* Außerdem soll das Land, das in der Lieferanschrift gespeichert wird, vom Typ einer Enumeration sein.
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
   std::string Ware;
};

/*** FUNCTIONS ***/
//leer

/*** PROGRAM STARTS HERE ***/
int main()
{
   bestellung Bestellung01;
   std::string Eingabe_Land;

   //Eingabe
   std::cout << "Geben Sie die gewünschte Ware ein: " << std::endl;
   std::cin >> Bestellung01.Ware;

   std::cout << "Geben Sie die Lieferadresse ein: " << std::endl;
   std::cout << " Anrede: " << std::endl;
   std::cin >> Bestellung01.Adresse.Anrede;
   std::cout << " Vorname: " << std::endl;
   std::cin >> Bestellung01.Adresse.Vorname;
   std::cout << " Nachname: " << std::endl;
   std::cin >> Bestellung01.Adresse.Nachname;
   std::cout << " Strasse: " << std::endl;
   std::cin >> Bestellung01.Adresse.Strasse;
   std::cout << " Hausnummer: " << std::endl;
   std::cin >> Bestellung01.Adresse.Hausnummer;
   std::cout << " Postleitzahl: " << std::endl;
   std::cin >> Bestellung01.Adresse.Postleitzahl;
   std::cout << " Ort: " << std::endl;
   std::cin >> Bestellung01.Adresse.Ort;
   std::cout << " Land (Deutschland, Oesterreich, Schweiz): " << std::endl;
   std::cin >> Eingabe_Land;

   //Überprüfe Land (3x)
   int counter=3;
   while (true)
   {
      if (Eingabe_Land == "Deutschland") {
         Bestellung01.Adresse.Land = Deutschland; 
         break;
      }
      else if (Eingabe_Land == "Oesterreich")
      {
         Bestellung01.Adresse.Land = Oesterreich; 
         break;
      }
      else if (Eingabe_Land == "Schweiz")
      {
         Bestellung01.Adresse.Land = Schweiz;
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

   std::cout << "Geben Sie die Kreditkartennummer ein: " << std::endl;
   std::cin >> Bestellung01.Bezahlkarte.Kreditkartennummer;
   std::cout << "Geben Sie das Gültigkeitsdatum der Kreditkarte ein: " << std::endl;
   std::cin >> Bestellung01.Bezahlkarte.Datum;

   //Ausgabe - Test
   std::cout << std::endl;
   std::cout << "Sie haben bestellt: " << std::endl;
   std::cout << "Ware: " << Bestellung01.Ware << std::endl;
   std::cout << std::endl;
   std::cout << "Anrede: " << Bestellung01.Adresse.Anrede << std::endl;
   std::cout << "Vorname: " << Bestellung01.Adresse.Vorname << std::endl;
   std::cout << "Nachname: " << Bestellung01.Adresse.Nachname << std::endl;
   std::cout << "Strasse: " << Bestellung01.Adresse.Strasse << std::endl;
   std::cout << "Hausnummer: " << Bestellung01.Adresse.Hausnummer << std::endl;
   std::cout << "Postleitzahl: " << Bestellung01.Adresse.Postleitzahl << std::endl;
   std::cout << "Ort: " << Bestellung01.Adresse.Ort << std::endl;
   std::cout << "Land: " << Bestellung01.Adresse.Land << std::endl;                            //Die Ausgabe erfolgt hier als int-Wert 
   std::cout << std::endl;
   std::cout << "Kreditkartennummer: " << Bestellung01.Bezahlkarte.Kreditkartennummer << std::endl;
   std::cout << "Gültigkeitsdatum: " << Bestellung01.Bezahlkarte.Datum << std::endl;
   std::cout << std::endl;
}

