
#ifndef UNI_CPP_FUNCTIONS_H
#define UNI_CPP_FUNCTIONS_H


struct Studentas {
    string vard, pav;
    vector <int> paz;
    int egz;
    float rez;
};


vector <Studentas> inputas();
void printas(vector <Studentas> sarasas);
float vidurkis(vector <int> pazymiai, int egzaminas);
float mediana(vector <int> pazymiai);
void input_loop(Studentas& laik);
void manual_input(Studentas& laik);
void random_input(Studentas& laik);
void read_file(int choice);
void parse_file(string const& filename);

#endif //UNI_CPP_FUNCTIONS_H
