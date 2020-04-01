#include <iostream>
#include <string>
#include<vector>
using namespace std;


class Carre
{

public:
   Carre();
  ~Carre();
   Carre(int);

   void put(const double valeur, int i, int j) ;
   double get(int, int) const;
   int taille();

   friend ostream &operator<<(ostream &os, Carre &c);
   Carre& operator=(const Carre &c);
   Carre operator+(const Carre &c);
   Carre operator-(const Carre &c);
   Carre operator*(const Carre &c);

   Carre moyenne(string s);


private:
   int mtaille;
   double **tab;



};
