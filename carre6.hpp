#include <iostream>
#include <string>
#include<vector>
//using namespace std;




template <class T> class CarreT;
template <class T> std::ostream &operator<<(std::ostream &os,  const  CarreT<T>& c);

template <class T>
class CarreT
{

public:
   CarreT();
  ~CarreT();
   CarreT(int);
   CarreT(int, T );

   void put(const T valeur, int i, int j) ;
   double get(int, int) const;
   int taille();

   friend std::ostream &operator<< <>(std::ostream &os,  const  CarreT<T>& c);
   CarreT<T>& operator=(const CarreT<T> &c);
   CarreT<T> operator+(const CarreT<T> &c);
   CarreT<T> operator-(const CarreT<T> &c);
   CarreT<T> operator*(const CarreT<T> &c);
   CarreT<T> operator*(const  T  &valeur);
   CarreT<T>& operator*=(const T &valeur);


   CarreT<T> moyenne(std::string s);


private:
   int mtaille;
    T **tab;



};
