#ifndef ZUBA_ZMOGUS_H
#define ZUBA_ZMOGUS_H

#include <string>
using std::string;

class Zmogus{
protected:
    string Vardas;
    string Pavarde;

public:
    Zmogus() : Vardas(""), Pavarde("") {};


    void setVardas(const string& v){Vardas = v;}
    void setPavarde(const string& p){Pavarde = p;}

    inline string vardas() const{return Vardas;}
    inline string pavarde() const{return Pavarde;}


    ~Zmogus();
};

#endif //ZUBA_ZMOGUS_H
