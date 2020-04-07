#include <iostream>

int main()
{
   double a, b, c, d;

   std::cout << "Geben Sie drei Zahlen ein: " << std::endl;

   //Einlesen a
   std::cout << "Erste Zahl: " << std::endl;
   std::cin >> a;

   //Einlesen b
   std::cout << "Zweite Zahl: " << std::endl;
   std::cin >> b;

   //Einlesen c
   std::cout << "Dritte Zahl: " << std::endl;
   std::cin >> c;

   //Kalkulation d: a -> +10 -> *b -> /c
   d = (a + 10) * b / c;

   //Ausgabe
   std::cout << "Das Ergebnis lautet: " << d << std::endl;
}
