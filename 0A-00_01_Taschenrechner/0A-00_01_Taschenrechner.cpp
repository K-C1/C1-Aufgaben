#include <iostream>


/* Aufgabe 1:
* Entwickeln Sie einen Taschenrechner, der die Eingabe zweier Zahlen erwartet und diese addieren, subtrahieren, multiplizieren und dividieren kann.
* Über eine einzige Präprozessor-Anweisung soll eingestellt werden können, ob nur mit Ganz- oder auch mit Kommazahlen gearbeitet werden kann. 
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

/*** SELECT HERE - DATATYPE ***/
#define GANZ    //Ganzzahlen
//#define KOMMA   //Kommazahlen



#if defined GANZ
#define DATATYPE int
#elif defined KOMMA
#define DATATYPE float
#else
#error Zahlentyp undefiniert!
#endif


/*** FUNCTIONS ***/
void sum(DATATYPE Summand1, DATATYPE Summand2)
{
   std::cout << "Summe: " << Summand1 + Summand2 << std::endl;
}

void diff(DATATYPE Minuend, DATATYPE Subtrahend)
{
   std::cout << "Differenz: " << Minuend - Subtrahend << std::endl;
}

void prod(DATATYPE Faktor1, DATATYPE Faktor2)
{
   std::cout << "Produkt: " << Faktor1 * Faktor2 << std::endl;
}

void quot(DATATYPE Dividend, DATATYPE Divisor)
{
   std::cout << "Quotient: " << Dividend / Divisor << std::endl;
}


/*** PROGRAM STARTS HERE ***/
int main()
{
   DATATYPE Zahl1, Zahl2;

#if defined GANZ
   std::cout << "Geben Sie zwei Ganzahlen ein." << std::endl;
#else
   std::cout << "Geben Sie zwei Komma- oder Ganzzahlen ein." << std::endl;
#endif

   std::cout << "Erste Zahl: " << std::endl;
   std::cin >> Zahl1;

   std::cout << "Zweite Zahl: " << std::endl;
   std::cin >> Zahl2;

   sum(Zahl1, Zahl2);

   diff(Zahl1, Zahl2);

   prod(Zahl1, Zahl2);

   quot(Zahl1, Zahl2);
}
