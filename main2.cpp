#include "carre2.hpp"
#include <iostream>
#include <algorithm>
#include <random>


Carre::Carre():mtaille(1)
{
    tab = new double*[mtaille];
    for (int i = 0; i < mtaille; i++){
        tab[i] = new double[mtaille];
    }
    tab[0][0]=rand()/(double)RAND_MAX;
}

Carre::Carre(int t):mtaille(t)
{
  tab = new double*[mtaille];
  for (int i = 0; i < mtaille; i++){
      tab[i] = new double[mtaille];
  }
  for (int i=0; i<mtaille; i++){
    for(int j=0;j<mtaille; j++){
      tab[i][j]=rand()/(double)RAND_MAX;
    }
  }
}
Carre::~Carre()
{
  for(int i = 0; i < mtaille; i++){
      delete[] tab[i];
  }

  //delete[] tab;
}

Carre::Carre(const Carre &other)
{
  mtaille = other.mtaille;
  tab     = other.tab;
}
void Carre::put(const double valeur, int i, int j)
{
   tab[i][j] = valeur;
}
double Carre::get(int i , int j) const
{
  return tab[i][j];
}

int Carre::taille()
{
  return mtaille;
}

Carre& Carre::operator=(const Carre &c)
{
  for(int i = 0; i < c.mtaille; i++){
      for(int j = 0; j < c.mtaille; j++){
         tab[i][j] = c.tab[i][j];
      }
  }

  return *this;



}

std::ostream &operator <<(std::ostream &os, Carre &c)
{
  for(int i = 0; i < c.mtaille; i++){
      for(int j = 0; j < c.mtaille; j++){
          os << c.tab[i][j] << " " ;
      }
      os << std::endl;
   }
  return os;
}



int main()
{
  int i,j;
  Carre Cd0;


  std::cout << "Test Carre\n";
  std::cout << Cd0;

  Carre Cd1(7);
  std::cout << "Test Carre de taille 7\n";
  std::cout << Cd1;

  // Partie 2 de l'examen

  std::cout << "Test fct put et taille()\n";

  std::default_random_engine dre;

  std::uniform_real_distribution<double> ddd(0,1);

  for (i=0;i<Cd1.taille();i++)
    for (j=0;j<Cd1.taille();j++)
      Cd1.put(ddd(dre),i,j);
  std::cout << "Test random \n";
  std::cout << Cd1;


  auto Cd1a = Cd1;

  std::cout << "Opérateur assignation\n";
  std::cout << "double\n" <<Cd1a;

  std::cout << "Test constructeur par recopie\n";

  auto Cd2(Cd1);
  std::cout << "Double\n"<<Cd2;

  return 0;

}
