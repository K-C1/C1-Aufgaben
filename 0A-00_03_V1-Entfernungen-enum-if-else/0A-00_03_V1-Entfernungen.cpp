#include <iostream>

/* Aufgabe 3:
* Entwickeln Sie ein C++-Programm, das nach Eingabe zweier Stadtnamen die Entfernung zwischen den beiden Städten in Kilometer ausgibt.
* Verwenden Sie folgende Daten, um Ihr Programm testen zu können:
* Die Entfernung zwischen Köln und München beträgt 480 Kilometer, zwischen München und Berlin 530 Kilometer und zwischen Berlin und Köln 500 Kilometer.
* Die Entfernung soll unabhängig von der Reihenfolge der Eingabe der Stadtnamen ausgegeben werden.
*
* Quelle: http://highscore.de/cpp/einfuehrung/index.html Boris Schäling
*/

/*** STRUCTS AND ENUMERATIONS ***/
enum stadt
{
   Berlin, Koeln, Muenchen
};


/*** FUNCTIONS ***/
stadt umwandeln(std::string Wert)
{
	if(Wert == "Berlin")
	{
		return Berlin;
	}
	else if (Wert == "Koeln")
	{
		return Koeln;
	}
	else if (Wert == "Muenchen")
	{
        return Muenchen;
	}
	else 
	{
		std::cout << "Eingabe ungültig!" << std::endl;
		exit (0);                                              //Programmabbruch
	}
}

int berechnen(int A, int B)
{
    if (A > B)
       std::swap(A, B);

    if (A == B)
	   return 0;
    else if (A == 0 && B == 1)
       return 500;
    else if (A == 0 && B ==2)
    	return 530;
    else if (A == 1)
    	return 480;
}


/*** PROGRAM STARTS HERE ***/
int main()
{
   std::string Eingabe1, Eingabe2;
   stadt Stadt1, Stadt2;
   int Strecke;

   //Eingabe
   std::cout << "Geben Sie zwei Städtenamen ein (Berlin, Koeln, Muenchen)." << std::endl;
   std::cout << "Erste Stadt: " << std::endl;
   std::cin >> Eingabe1;

   std::cout << "Zweite Stadt: " << std::endl;
   std::cin >> Eingabe2;

   Stadt1 = umwandeln(Eingabe1);
   Stadt2 = umwandeln(Eingabe2);

   Strecke = berechnen(Stadt1, Stadt2);

   //Ausgabe
   std::cout << "Die Entfernung zwischen den beiden Städten beträgt "  << Strecke << " Kilometer." << std::endl;
}