#include "carre4.hpp"
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

Carre Carre::operator+(const Carre &c)
{
    Carre c1(mtaille);
    for(int i = 0; i < mtaille; i++){
        for(int j = 0; j < mtaille; j++){
           c1.tab[i][j] = tab[i][j] + c.tab[i][j];
        }
    }

    return c1;

}
Carre  Carre::operator-(const Carre &c)
{
  Carre c1(mtaille);
  for(int i = 0; i < mtaille; i++){
      for(int j = 0; j < mtaille; j++){
         c1.tab[i][j] = tab[i][j] - c.tab[i][j];
      }
  }
  return c1;
}
Carre Carre::operator*(const Carre &c)
{
  Carre c1(mtaille);
  for(int i = 0; i < mtaille; i++){
      for(int j = 0; j < mtaille; j++){
        for(int k = 0; k < mtaille; k++){
          c1.tab[i][j] += tab[i][k]*c.tab[k][j];
        }
      }
  }
  return c1;


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


Carre Carre::moyenne(std::string c)
{
    Carre c1(mtaille);
    if(c == "miroir"){
      for(int i = 1; i < mtaille-1; i++){
         c1.tab[i][0] = (tab[i-1][0] + 2*tab[i][i+1] + tab[i+1][0])/2;
         c1.tab[i][mtaille-1] = (tab[i-1][mtaille-1] + 2*tab[i][mtaille-2] + tab[i+1][mtaille-1])/4;
      }
      for(int j = 1; j < mtaille-1; j++){
        c1.tab[0][j] = (2*tab[j+1][j] + tab[0][j+1] + tab[0][j-1] )/4;
        c1.tab[mtaille-1][j] = (2*tab[mtaille-2][j] + tab[mtaille-1][j-1] + tab[mtaille-1][j+1])/4;
      }

      c1.tab[0][0] = (tab[1][0] + tab[0][1])/2;
      c1.tab[mtaille-1][0] = (tab[mtaille-2][0] + tab[mtaille-1][2])/2;

      c1.tab[0][mtaille-1] = (tab[0][mtaille-2] + tab[1][mtaille-1])/2;
      c1.tab[mtaille-1][mtaille-1] = (tab[mtaille-2][mtaille-1] + tab[mtaille-1][mtaille-2])/2;



      for(int i = 1; i < mtaille-1; i++){
        for(int j = 0; j < mtaille-1; j++){
          c1.tab[i][j] = (tab[i+1][j]+ tab[i-1][j] + tab[i][j+1] + tab[i][j-1])/4;
        }
      }

      return c1;

    }

    /*else if(c == "tore")
    {
         std::cout << "methode pas encore implémentée" << '\n';
    }*/
    else{
        std::string err =  "méthode non impléméentée!!!";
        throw err;
    }
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
      Cd1.put(i,j,ddd(dre));
  std::cout << "Test random \n";
  std::cout << Cd1;


  auto Cd1a = Cd1;

  std::cout << "Opérateur assignation\n";
  std::cout << "double\n" <<Cd1a;

  std::cout << "Test constructeur par recopie\n";

  auto Cd2(Cd1);
  std::cout << "Double\n"<<Cd2;

  // partie 3 de l'examen

  std::cout << " Test des operateurs arithmétiques\n";


  Carre Cd3(Cd1);


  auto Cd4=Cd1+Cd2;
  std::cout << "Cd4 = Cd1 + Cd2\n";
  std::cout << Cd4;
  auto Cd5=Cd1-Cd2;
  std::cout << "Cd5 = Cd1 - Cd2\n";
  std::cout << Cd5;
  auto Cd6=Cd1*Cd2;
  std::cout << "Cd6 = Cd1 * Cd2\n";
  std::cout << Cd6;

  // Partie 4 de l'examen

  auto Cd6a(Cd6);

  std::cout << "Test moyenne miroir\n";
  Cd6a.moyenne("miroir");
  std::cout << Cd6a;

  //auto Cd6b(Cd6);

  //std::cout << "Test moyenne tore\n";

  //Cd6b.moyenne("tore");
  //std::cout << Cd6b;


}
