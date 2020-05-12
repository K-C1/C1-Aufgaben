#include <iostream>
#include <string>
#include <unistd.h>            //sleep, usleep
#include <iomanip>             //precision
#include "bankkonto.h"

/* Aufgabe 2:
* Entwickeln Sie eine C++-Anwendung zur Simulation eines Bankautomaten.
* Der Anwender soll einen Benutzernamen (der die EC-Karte repräsentiert) und eine dazugehörige PIN eingeben, um Zugriff auf sein Konto zu erhalten.
* Insgesamt soll die Beispiel-Anwendung drei Konten mit unterschiedlichen Benutzernamen und PINs unterstützen.
* Ist das Einloggen erfolgreich, kann der Anwender zwischen Kontostandanzeige und Auszahlung eines Betrags wählen.
* Das Programm soll in einer Endlosschleife laufen, um mehrmaliges Einloggen in den Bankautomaten zu ermöglichen.
* Setzen Sie die drei Konten auf beliebige Werte, um das Programm zu testen, und loggen Sie sich mehrmals mit jedem Benutzer ein, um den Kontostand anzuzeigen und Geld abzuheben. 
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/


/*** GLOBAL OBJECTS ***/
//Vorbereitung - Erstellen der Konten
bankkonto Konten[] =
{
    bankkonto("Girokonto", "ABC", "123", 2730.30),      //std::string Konto, std::string Benutzer, std::string Passwort, float Betrag
    bankkonto("Ferienkonto", "ZRH", "456", 4500.00), 
    bankkonto("Sparkonto", "MFK", "789", 134321.55)
};
int AnzahlKonten = sizeof(Konten)/sizeof(Konten[0]);


/*** FUNCTIONS ***/
void funWaiting()                           //Have some fun ;-)
{
    for (int i = 0; i < 25; ++i)
    {
        usleep(100000);                     //Pause
        std::cout << "." << std::flush;
    }
    std::cout << "...." << std::endl;
}

void einziehenKarte()
{
    sleep(5);
    std::cout << "\n    !!! Karte eingezogen !!!\n" << std::endl;             //TODO Karte sperren (als Klassen-Methode)
    sleep(5);
}

void checkDispo(float Kontostand)
{
    if (Kontostand < 0)
        std::cout << "    Achtung: Es fallen Dispozinsen an!\n" << std::endl;
}

bankkonto* sucheKonto(std::string Karte)
{
    for (int j = 0; j < AnzahlKonten; ++j)
    {
        if (Konten[j].isRegistered(Karte))
        {
            return &Konten[j];     
        }
    }
    return 0;
}


/*** PROGRAM STARTS HERE ***/
int main()
{
    std::cout << std::fixed;                          //Ausgabe von float Werten mit zwei Nachkommastellen
    std::cout << std::setprecision(2);                //...und auf zwei Nachkommastellen genau 

    std::string EingabeKarte;                         //EC-Karte
    std::string EingabePIN;                           //PIN
    char EingabeAuswahl;                              //Auswahl im Benutzermenu
    float Betrag;                                     //Betrag zum Abheben
    bankkonto* aktivesKonto;                          //Pointer auf das aktivierte Konto

    //Vorbereitung - Ausgabe der Kontoinformationen
    std::cout << "**** KONTOINFORMATIONEN ****" << "\n* " << std::endl;
    for (int i = 0; i < AnzahlKonten; ++i)
    {
        std::cout << "* " << Konten[i].account << ": " << std::endl;
        Konten[i].printKontoinformationen();
    }
    std::cout << "****************************" << "\n" << std::endl;
    
    //User Interface starts here
    while (true)
    {
        aktivesKonto = 0;                             //Pointer zeigt auf undefinierten Wert (Nicht-existenten Speicherort 0)

        //Eingaben und Prüfungen
        std::cout << "\n*** Willkommen bei ~ C-plus-plus Bank ~ *** \n    Geben Sie Ihre EC-Karte ein: " << std::endl;
        std::cin >> EingabeKarte;
        std::cout << "    Bitte warten - Ihre EC-Karte wird geprüft ...." << std::flush;
        funWaiting();
        aktivesKonto = sucheKonto(EingabeKarte);      //Pointer setzen auf gefundenes Konto
        
        if (aktivesKonto == 0)
        {  
            std::cout << "\n    ABBRUCH - Ihre EC-Karte ist ungültig." << std::endl;
            sleep(2);
            continue;
        }
        std::cout << "\n    Ihre Karte wurde geprüft." << std::endl;
        sleep(2);
        std::cout << "\n    Geben Sie Ihre PIN ein: " << std::endl;
        std::cin >> EingabePIN;
        std::cout << "    Bitte warten - Ihre PIN wird geprüft ...." << std::flush;
        funWaiting();
        if (!aktivesKonto->login(EingabePIN))
        {
            std::cout << "\n    ABBRUCH - Achtung: Sicherheitsproblem!!\n" << std::endl;
            sleep(5);
            continue;
        }

        //Kontoaktivitäten starten
        std::cout << "\n    Willkommen auf Ihrem " << aktivesKonto->account << ".\n" << std::endl;
        
        while (aktivesKonto->isAuthenticated())
        {
            sleep(2);
            std::cout << "\n    Was möchten Sie als nächstes tun:\n    (1) Kontostand anzeigen\n    (2) Geld abheben\n    (X) Logout" << std::endl;
            std::cin >> EingabeAuswahl;

            switch (EingabeAuswahl)
            {
                case '1':                              //Kontostand anzeigen
                {
                    std::cout << "\n    Aktueller Kontostand: " << aktivesKonto->getKontostand() << " Thaler\n" << std::endl;
                    checkDispo(aktivesKonto->getKontostand());
                    break;
                }
                case '2':                             //Geld abheben
                {
                    std::cout << "\n    Geben Sie den gewünschten Betrag ein: " << std::endl;
                    std::cin >> Betrag;
                    aktivesKonto->abhebenBetrag(Betrag);
                    checkDispo(aktivesKonto->getKontostand());
                    break;
                }
                case 'X':                             //Ausloggen
                {
                    aktivesKonto->logout();
                    break;
                }
                default:
                {
                    std::cout << "    Ungültige Auswahl\n" << std::endl;
                    break;
                }
            }
        }

        //Kontoaktivitäten beenden
        std::cout << "    Bitte entnehmen Sie Ihre Karte.\n    Bestätigen mit E(X)IT" << std::endl;
        std::cin >> EingabeAuswahl;

        switch(EingabeAuswahl)
        {
            case 'X':
            {
                std::cout << "\n*** Auf Wiedersehen bei ~C-plus-plus Bank~ ***\n" << std::endl;
                sleep(3);
                break;
            }
            default:
            {
                einziehenKarte();
            }
        }
    } //END User Interface 
}
