#include <iostream>
#include <string>

/* Aufgabe 3:
* Erweitern Sie die C++-Anwendung aus Aufgabe 2 dahingehend, dass Sie eine Funktion definieren, die keinen Rückgabewert liefert und einen einzigen Parameter erwartet.
* Diese Funktion rufen Sie auf, nachdem der Anwender seine Bestellung vorgenommen hat, und übergeben ihr die gesamte Bestellung.
* Die Funktion soll daraufhin die bestellten Waren, die Lieferadresse und die Kreditkartendaten auf den Bildschirm ausgeben.
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
void AusgabeBestellung(bestellung Auftrag)
{
   int WareAnzahl = sizeof(Auftrag.Ware)/sizeof(Auftrag.Ware[0]);

   std::cout << std::endl;
   std::cout << "Sie haben bestellt: " << std::endl;
   for(int j = 0; j < WareAnzahl; ++j)
   {
      std::cout << "Artikel " << j+1 << " : " << Auftrag.Ware[j] << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Anrede: " << Auftrag.Adresse.Anrede << std::endl;
   std::cout << "Vorname: " << Auftrag.Adresse.Vorname << std::endl;
   std::cout << "Nachname: " << Auftrag.Adresse.Nachname << std::endl;
   std::cout << "Strasse: " << Auftrag.Adresse.Strasse << std::endl;
   std::cout << "Hausnummer: " << Auftrag.Adresse.Hausnummer << std::endl;
   std::cout << "Postleitzahl: " << Auftrag.Adresse.Postleitzahl << std::endl;
   std::cout << "Ort: " << Auftrag.Adresse.Ort << std::endl;
   switch (Auftrag.Adresse.Land)
   {
      case 0: 
      {
         std::cout << "Land: Deutschland" << std::endl;
         break;
      }
      case 1: 
      {
         std::cout << "Land: Oesterreich" << std::endl;
         break;
      }
      case 2: 
      {
         std::cout << "Land: Schweiz" << std::endl;
         break;
      }
      default:
         std::cout << "ERROR: Unbekannter Fehler!" << std::endl;
   }

   std::cout << std::endl;
   std::cout << "Kreditkartennummer: " << Auftrag.Bezahlkarte.Kreditkartennummer << std::endl;
   std::cout << "Gültigkeitsdatum: " << Auftrag.Bezahlkarte.Datum << std::endl;
   std::cout << std::endl;
}


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
   std::cout << " Nachname: " << std::endl;
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

   //Ausgabe
   AusgabeBestellung(Bestellung10);
}

