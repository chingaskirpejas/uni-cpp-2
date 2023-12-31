#include "my_lib.h"
#include "functions.h"

//inputo funkcija

bool pagal_varda(Studentas& a, Studentas& b)
{
    return a.vardas()<b.vardas();
}



void manual_input(Studentas& laik)
{
    cout<<"Ivedus pazymi paspauskite enter"<<endl;
    cout<<"Pazymiu ivedimui baigti paspauskite q arba enter"<<endl;
    cout<<"Iveskite studento pazymius: ";
    input_loop(laik);
}

void random_input(Studentas& laik)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(1, 10);

    srand(time(0));
    for(int i=0; i<10; i++) {
        int j = rand() % 10 + 1;
        laik.paz.push_back(j);
    }
    laik.egz = rand() % 10 + 1;
}

void input_loop(Studentas& laik)
{
    vector<double> pazymiai;
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
        pazymiai.push_back(in);
    }
    laik.setPazymiai(pazymiai);

}

// funkcija apskaiciuojanti vidurki ir grazinanti ji
float vidurkis(vector <int> pazymiai, int egzaminas)
{

}


// funkcija grazinanti mediana
float mediana(vector <int> pazymiai)
{

}

void printas(vector <Studentas>& sarasas)
{
    sort(sarasas.begin(), sarasas.end(), pagal_varda);
    string decision;
    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
    cin>>decision;
    while(decision != "V" && decision != "v" && decision != "m" && decision != "M")
    {
        cout<<"Neteisingai ivestas simbolis, bandykite dar karta: "<<endl;
        cin>>decision;
    }

    if(decision == "v" || decision == "V")
    {
        cout<<"              Vardas               Pavarde        Vid.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<vidurkis(stud.paz, stud.egz)<<" "<<setw(10)<<&stud<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde        Med.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<mediana(stud.paz)<<" "<<setw(10)<<&stud<<endl;
        }
    }
}

void printas_list(list<Studentas>& sarasas)
{
    sarasas.sort(pagal_varda);
    string decision;
    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
    cin>>decision;
    while(decision != "V" && decision != "v" && decision != "m" && decision != "M")
    {
        cout<<"Neteisingai ivestas simbolis, bandykite dar karta: "<<endl;
        cin>>decision;
    }

    if(decision == "v" || decision == "V")
    {
        cout<<"              Vardas               Pavarde        Vid.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<vidurkis(stud.paz, stud.egz)<<" "<<setw(10)<<&stud<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde        Med.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<mediana(stud.paz)<<" "<<setw(10)<<&stud<<endl;
        }
    }
}