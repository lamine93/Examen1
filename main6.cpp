#include "carre6.hpp"
#include <iostream>
#include <algorithm>
#include <random>


template <class T>
CarreT<T>::CarreT()
{
    mtaille =1;
    tab = new T*[mtaille];
    for (int i = 0; i < mtaille; i++){
        tab[i] = new T[mtaille];
    }
    tab[0][0]=rand()/(T)RAND_MAX;
};
template <class T>
CarreT<T>::CarreT(int t)
{
  mtaille=t;
  tab = new T*[mtaille];
  for (int i = 0; i < mtaille; i++){
      tab[i] = new T[mtaille];
  }
  for (int i=0; i<mtaille; i++){
    for(int j=0;j<mtaille; j++){
      tab[i][j]=rand()/(T)RAND_MAX;
    }
  }
};
template <class T>
CarreT<T>::CarreT(int t, T v)
{
  mtaille = t;
  tab = new T*[mtaille];
  for (int i = 0; i < mtaille; i++){
      tab[i] = new T[mtaille];
  }
  for (int i=0; i<mtaille; i++){
    for(int j=0;j<mtaille; j++){
      tab[i][j]= v;
    }
  }
};
template <class T>
CarreT<T>::~CarreT()
{
  for(int i = 0; i < mtaille; i++){
      delete[] tab[i];
  }

  //delete[] tab;
}
template <class T>
void CarreT<T>::put(const T valeur, int i, int j)
{
   tab[i][j] = valeur;
}
template <class T>
double CarreT<T>::get(int i , int j) const
{
  return tab[i][j];
};

template <class T>
int CarreT<T>::taille()
{
  return mtaille;
};
template <class T>
CarreT<T> CarreT<T>::operator+(const CarreT &c)
{
    CarreT c1(mtaille);
    for(int i = 0; i < mtaille; i++){
        for(int j = 0; j < mtaille; j++){
           c1.tab[i][j] = tab[i][j] + c.tab[i][j];
        }
    }

    return c1;

};
template <class T>
CarreT<T>  CarreT<T>::operator-(const CarreT &c)
{
  CarreT c1(mtaille);
  for(int i = 0; i < mtaille; i++){
      for(int j = 0; j < mtaille; j++){
         c1.tab[i][j] = tab[i][j] - c.tab[i][j];
      }
  }
  return c1;
};
template <class T>
CarreT<T> CarreT<T>::operator*(const CarreT &c)
{
  CarreT c1(mtaille);
  for(int i = 0; i < mtaille; i++){
      for(int j = 0; j < mtaille; j++){
        for(int k = 0; k < mtaille; k++){
          c1.tab[i][j] += tab[i][k]*c.tab[k][j];
        }
      }
  }
  return c1;


};
template <class T>
CarreT<T> CarreT<T>::operator*(const T& valeur)
{
    CarreT c1(mtaille);

    for(int i = 0; i < mtaille; i++){
        for(int j = 0; j < mtaille; j++){
           c1.tab[i][j] = tab[i][j]*valeur;
        }
    }

    return c1;

};
template <class T>
CarreT<T>& CarreT<T>::operator*=(const T& valeur)
{
  for(int i = 0; i < mtaille; i++){
      for(int j = 0; j < mtaille; j++){
         tab[i][j]*=valeur ;
      }
  }
  return *this;
};

template <class T>
std::ostream& operator<<(std::ostream &os, const  CarreT<T>& c)
{
  for(int i = 0; i < c.mtaille; i++){
      for(int j = 0; j < c.mtaille; j++){
          os << c.tab[i][j] << " " ;
      }
      os << std::endl;
   }
  return os;
};

template <class T>
CarreT<T> CarreT<T>::moyenne(std::string c)
{
    CarreT c1(mtaille);
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
    else{
        std::cout<<" méthode non impléméentée!!! " << std::endl;
    }
};



int main()
{
  int i,j;

  // Partie 1 de l'examen
  CarreT<int> Ci0;
  CarreT<float> Cf0;
  CarreT<double> Cd0;

  std::cout << "Test Ci0 CarreT<int>\n";
  std::cout << Ci0;

  std::cout << "Test Cf0 CarreT<float>\n";
  std::cout << Cf0;

  std::cout << "Test Cd0 CarreT<double>\n";
  std::cout << Cd0;

  CarreT<int> Ci1(5);
  std::cout << "Test Ci1 CarreT<int> de taille " <<Ci1.taille()<<"\n";
  std::cout << Ci1;

  CarreT<float> Cf1(6);
  std::cout << "Test Cf1 CarreT<float>de taille "  <<Cf1.taille()<<"\n";
  std::cout << Cf1;

  CarreT<double> Cd1(7);
  std::cout << "Test Cd1 CarreT<double> de taille "  <<Cd1.taille()<<"\n";
  std::cout << Cd1;

  // Partie 2 de l'examen

  std::default_random_engine dre;
  std::uniform_int_distribution<int> ddi(0,1);


  for (i=0;i<Ci1.taille();i++)
    for (j=0;j<Ci1.taille();j++)
      {
	Ci1.put(i,j,ddi(dre));
      }
  std::cout << "Test Ci1 random int\n";
  std::cout << Ci1;


  std::uniform_real_distribution<float> ddf(0,1);

  for (i=0;i<Cf1.taille();i++)
    for (j=0;j<Cf1.taille();j++)
      Cf1.put(i,j,ddf(dre));
  std::cout << "Test Cf1 random float\n";
  std::cout << Cf1;

  std::uniform_real_distribution<double> ddd(0,1);

  for (i=0;i<Cd1.taille();i++)
    for (j=0;j<Cd1.taille();j++)
      Cd1.put(i,j,ddd(dre));
  std::cout << "Test Cd1 random double\n";
  std::cout << Cd1;

  // again

  CarreT<int> Ci2(Ci1);
  CarreT<float> Cf2(Cf1);
  CarreT<double> Cd2(Cd1);

  for (i=0;i<Ci2.taille();i++)
    for (j=0;j<Ci2.taille();j++)
      {
	Ci2.put(i,j,ddi(dre));
      }
  std::cout << "Test Ci2 random int\n";
  std::cout << Ci2;

  for (i=0;i<Cf2.taille();i++)
    for (j=0;j<Cf2.taille();j++)
      Cf2.put(i,j,ddf(dre));
  std::cout << "Test Cf2 random float\n";
  std::cout << Cf2;

  for (i=0;i<Cd2.taille();i++)
    for (j=0;j<Cd2.taille();j++)
      Cd2.put(i,j,ddd(dre));
  std::cout << "Test Cd2 random double\n";
  std::cout << Cd2;



  auto Ci2a = Ci2;
  auto Cf2a = Cf2;
  auto Cd2a = Cd2;

  std::cout << "Opérateur assignation\n";
  std::cout << "int auto Ci2a = Ci2; \n" <<Ci2a;
  std::cout << "float auto Cf2a = Cf2; \n" <<Cf2a;
  std::cout << "double  auto Cd2a = Cd2;\n" <<Cd2a;

  std::cout << "Test constructeur par recopie\n";
  auto Ci2b(Ci2);
  std::cout << "Entier auto Ci2b(Ci2);  \n"<< Ci2b;
  auto Cf2b(Cf2);
  std::cout << "Float auto Cf2b(Cf2); \n"<<Cf2b;
  auto Cd2b(Cd2);
  std::cout << "Double auto Cd2b(Cd2);\n"<<Cd2b;

  // partie 3 de l'examen

  std::cout << " Test des operateurs arithmétiques\n";

  CarreT<int> Ci3(Ci1);
  CarreT<float> Cf3(Cf1);
  CarreT<double> Cd3(Cd1);


  auto Ci4=Ci1+Ci2;
  std::cout << "Ci4 = Ci1 + Ci2\n";
  std::cout << Ci4;
  auto Ci5=Ci1-Ci2;
  std::cout << "Ci5 = Ci1 - Ci2\n";
  std::cout << Ci5;
  auto Ci6=Ci1*Ci2;
  std::cout << "Ci6 = Ci1 * Ci2\n";
  std::cout << Ci6;

  auto Cf4=Cf1+Cf2;
  std::cout << "Cf4 = Cf1 + Cf2\n";
  std::cout << Cf4;
  auto Cf5=Cf1-Cf2;
  std::cout << "Cf5 = Cf1 - Cf2\n";
  std::cout << Cf5;
  auto Cf6=Cf1*Cf2;
  std::cout << "Cf6 = Cf1 * Cf2\n";
  std::cout << Cf6;

  auto Cd4=Cd1+Cd2;
  std::cout << "Cd4 = Cd1 + Cd2\n";
  std::cout << Cd4;
  auto Cd5=Cd1-Cd2;
  std::cout << "Cd5 = Cd1 - Cd2\n";
  std::cout << Cd5;
  auto Cd6=Cd1*Cd2;
  std::cout << "Cd6 = Cd1 * Cd2\n";
  std::cout << Cd6;


  CarreT<int> Ci7b(5,3);
  std::cout << " Ci7b(5,3);\n";
  std::cout << Ci7b;

  CarreT<double> Cd7b(5,2.0);
  std::cout << " Cd7b(5,2.0);\n";
  std::cout << Cd7b;

  std::cout << "Test mutiplication par un T\n";

  /*auto Ci7 = 3 * Ci7b;
  auto Cd7 = 3.0 * Cd7b;

  std::cout << " Ci7 = 3 * Ci7b\n";
  std::cout << Ci7;
  std::cout << " Cd7 = 3.0 * Cd7b\n";
  std::cout << Cd7;*/


  auto Ci8 = Ci7b * 3;
  auto Cd8 = Cd7b * 3.0;

  std::cout << " Ci8 = Ci7b * 3\n";
  std::cout << Ci8;
  std::cout << " Cd8 = Cd7b * 3.0\n";
  std::cout << Cd8;


  Ci7b *= 2;
  Cd7b *= 2.0;

  std::cout << "Ci7b *=2;\n";
  std::cout << Ci7b;
  std::cout << "Cd7b *=2.0;\n";
  std::cout << Cd7b;


}
