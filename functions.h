
#ifndef UNI_CPP_FUNCTIONS_H
#define UNI_CPP_FUNCTIONS_H


class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> nd_;

public:
    Studentas() : egzaminas_(0) { }  // default konstruktorius
    Studentas(std::istream& is);
    inline std::string vardas() const { return vardas_; }    // get'eriai, inline
    inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline
    double galBalas(double (*) (vector<double>) = mediana) const;  // get'eriai
    std::istream& readStudent(std::istream&);  // set'eriai
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
