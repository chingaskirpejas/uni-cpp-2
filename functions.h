#ifndef UNI_CPP_FUNCTIONS_H
#define UNI_CPP_FUNCTIONS_H


class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> paz;
    double rez;

public:
    Studentas() : egzaminas_(0), rez(0) {}
    Studentas(std::istream& is);
    // Destructor
    ~Studentas() {}

    // Copy constructor
    Studentas(const Studentas& other)
            : vardas_(other.vardas_),
              pavarde_(other.pavarde_),
              egzaminas_(other.egzaminas_),
              paz(other.paz),
              rez(other.rez) {
    }

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egzaminas_ = other.egzaminas_;
            paz = other.paz;
            rez = other.rez;
        }
        return *this;
    }


    void clearPazymiai(){paz.clear();}

    // geteriai
    inline std::string vardas() const {return vardas_;}
    inline std::string pavarde() const {return pavarde_;}
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
    void setVardas(const string& vardas){vardas_ = vardas;}
    void setPavarde(const string& pavarde){pavarde_ = pavarde;}
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

        out<<"Vardas Pavarde: "<<studentas.vardas_<<" "<<studentas.pavarde_<<endl;
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
        in >> studentas.vardas_;
        cout<<"Iveskite pavarde: ";
        in>>studentas.pavarde_;
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
