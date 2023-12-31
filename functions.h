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
    Studentas() : egzaminas_(0) { }  // default konstruktorius
    Studentas(std::istream& is);

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
        float mediana;
        size_t size = paz.size();
        if (size % 2 == 0)
        {
            mediana = static_cast<float>(paz[size / 2 - 1] + paz[size / 2]) / 2;
        }
        else
        {
            mediana = paz[size / 2];
        }

        return mediana;
    }
    inline double getRez() const {return rez;}
    // seteriai
    void setVardas(const string& vardas){vardas_ = vardas;}
    void setPavarde(const string& pavarde){pavarde_ = pavarde;}
    void setPazymiai(const vector<double>& pazymiai){
        sort(pazymiai.begin(), pazymiai.end());
        paz = pazymiai;
    }
    void setEgz(const int& egzas){egzaminas_ = egzas;}

    double galBalas(double (*) (vector<double>) = mediana) const;
    std::istream& readStudent(std::istream&);
};

list<Studentas> list_inputas();
vector <Studentas> inputas();
void printas(vector <Studentas>& sarasas);
void printas_list(list<Studentas>& sarasas);
float vidurkis(vector <int> pazymiai, int egzaminas);
float mediana(vector <int> pazymiai);
void input_loop(Studentas& laik);
void manual_input(Studentas& laik);
void random_input(Studentas& laik);
void read_file(int choice);
void parse_file(string const& filename);
bool pagal_varda(Studentas& a, Studentas& b);

#endif //UNI_CPP_FUNCTIONS_H
