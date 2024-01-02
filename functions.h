#ifndef UNI_CPP_FUNCTIONS_H
#define UNI_CPP_FUNCTIONS_H

#include "my_lib.h"

class Zmogus{
protected:
    string Vardas, Pavarde;

public:
    Zmogus() {}

    Zmogus(const Zmogus& other)
            : Vardas(other.Vardas),
              Pavarde(other.Pavarde) {}

    Zmogus& operator=(const Zmogus& other) {
        if (this != &other) {
            Vardas = other.Vardas;
            Pavarde = other.Pavarde;
        }
        return *this;
    }

    // getteriai
    string vardas() const {return Vardas;}
    string pavarde() const {return Pavarde;}

    //setteriai
    void setVardas(const string &v){Vardas = v;}
    void setPavarde(const string &p){Pavarde = p;}


};


class Studentas : public Zmogus{
private:
    double egzaminas_;
    std::vector<double> paz;
    double rez;

public:
    Studentas() : egzaminas_(0), rez(0) {}
    Studentas(std::istream& is);
    // Destructor
    ~Studentas(){}
    // Copy constructor
    Studentas(const Studentas& other)
            : Zmogus(other),
              egzaminas_(other.egzaminas_),
              paz(other.paz),
              rez(other.rez) {}

    Studentas& operator=(const Studentas& other) {
        if (this != &other)
        {

            static_cast<Zmogus &>(*this) = static_cast<const Zmogus &>(other);

            egzaminas_ = other.egzaminas_;
            paz = other.paz;
            rez = other.rez;
        }
        return *this;
    }

    void clearPazymiai(){paz.clear();}

    // geteriai
    inline double egzaminas() const {return egzaminas_;}
    inline double getVidurkis() const{
        float rezultatas=0;
        for (auto &a: paz)
        {
            rezultatas += a;
        }
        rezultatas = (rezultatas/paz.size())*0.4; // pazymiu vidurkis
        rezultatas = rezultatas + (egzaminas_*0.6); // pridedam egzamino svori/dali
        return rezultatas;
    }
    inline double getMediana() const {

        std::vector<double> sortedPaz = paz;
        std::sort(sortedPaz.begin(), sortedPaz.end());

        double mediana;
        size_t size = sortedPaz.size();

        if (size % 2 == 0) {
            mediana = static_cast<double>(sortedPaz[size / 2 - 1] + sortedPaz[size / 2]) / 2.0;
        } else {
            mediana = sortedPaz[size / 2];
        }

        return mediana;
    }

    inline double getRez() const {return rez;}

    // seteriai
    void setPazymiai(const vector<double>& pazymiai){
        paz = pazymiai;
    }
    void setRez()
    {
        rez = getVidurkis();
    }


    void setEgz(const int& egzas){egzaminas_ = egzas;}

    // outputo << overloadas
    friend std::ostream& operator<<(std::ostream& out, const Studentas& studentas)
    {

        out<<"Vardas Pavarde: "<<studentas.Vardas<<" "<<studentas.Pavarde<<endl;
        out<<"Pazymiai: "<<endl;
        for(const auto& a: studentas.paz)
        {
            out<<a<<" ";
        }
        out<<endl;
        out<<"Egzaminas: "<<studentas.egzaminas_<<endl;
        out<<"Vidurkis: "<<studentas.rez<<endl;
        out<<"------------------------------------"<<endl;
        return out;
    }

    // inputo >> overloadas
    friend std::istream& operator>>(std::istream& in, Studentas& studentas)
    {
        cout<<"Iveskite varda: ";
        in >> studentas.Vardas;
        cout<<"Iveskite pavarde: ";
        in>>studentas.Pavarde;
        cout<<"Pasirinkite kaip norite ivesti studento pazymius: autogeneracija(rasykite a), rankiniu budu(rasykite r):"<<endl;
        string choice;
        cin>>choice;
        if(choice == "a" || choice == "A")
        {
            std::random_device rd;
            std::mt19937 engine(rd());
            std::uniform_int_distribution<> dist(1, 10);
            for(int i=0; i<10; i++)
            {
                studentas.paz.push_back((dist(engine)));
            }
            studentas.egzaminas_ = dist(engine);
        }
        else if(choice == "r" || choice == "R")
        {
            cout<<"Ivedus pazymi paspauskite enter"<<endl;
            cout<<"Pazymiu ivedimui baigti paspauskite q arba enter"<<endl;
            cout<<"Iveskite studento pazymius: ";

            string paz;
            cin.ignore();
            while(true)
            {
                getline(cin, paz);
                if(paz == "q" || paz.empty())
                {
                    break;
                }
                int in = std::stod(paz);
                if(in<0 || in>10)
                {
                    cout<<"Ivedete bloga skaiciu";
                    continue;
                }
                studentas.paz.push_back(in);
            }
            cout<<endl<<"Iveskite egzamina: ";
            in>>studentas.egzaminas_;
        }
        studentas.setRez();

        return in;
    }
};

list<Studentas> list_inputas();
vector <Studentas> inputas();
void printas(vector <Studentas>& sarasas);
void printas_list(list<Studentas>& sarasas);
void read_file(int choice);
void parse_file(string const& filename);
bool pagal_varda(Studentas& a, Studentas& b);

#endif //UNI_CPP_FUNCTIONS_H