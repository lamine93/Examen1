
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
class Carre{

  public:
    int taille;
    double **tab;


    Carre();
    ~Carre();
    Carre(int taille);
    friend ostream &operator<<(ostream &os, Carre &c);


};
