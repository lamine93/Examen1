#include "carre1.hpp"
#include <iostream>



Carre::Carre():taille(1)
{
    tab = new double*[taille];
    for (int i = 0; i < taille; i++){
        tab[i] = new double[taille];
    }
    tab[0][0]=rand()/(double)RAND_MAX;
}

Carre::Carre(int t):taille(t)
{
  tab = new double*[taille];
  for (int i = 0; i < taille; i++){
      tab[i] = new double[taille];
  }
  for (int i=0; i<taille; i++){
    for(int j=0;j<taille; j++){
      tab[i][j]=rand()/(double)RAND_MAX;
    }
  }
}
Carre::~Carre()
{
  for(int i = 0; i < taille; i++){
      delete[] tab[i];
  }

  delete[] tab;
}

std::ostream &operator <<(std::ostream &os, Carre &c)
{
  for(int i = 0; i < c.taille; i++){
      for(int j = 0; j < c.taille; j++){
          os << c.tab[i][j] << " " ;
      }
      os << std::endl;
   }
  return os;
}


int main()
{
  int i,j;
  // Partie 1 de l'examen
  Carre Cd0;

  std::cout << "Test Carre\n";
  std::cout << Cd0;


  Carre Cd1(7);
  std::cout << "Test Carre de taille 7\n";
  std::cout << Cd1;

}
