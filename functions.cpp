#include "my_lib.h"
#include "functions.h"

bool pagal_varda(Studentas& a, Studentas& b)
{
    return a.vardas()<b.vardas();
}

void printas(vector <Studentas>& sarasas)
{
    sort(sarasas.begin(), sarasas.end(), pagal_varda);
    for(auto& stud : sarasas)
    {
        cout<<stud;
    }
//
//    string decision;
//    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
//    cin>>decision;
//    while(decision != "V" && decision != "v" && decision != "m" && decision != "M")
//    {
//        cout<<"Neteisingai ivestas simbolis, bandykite dar karta: "<<endl;
//        cin>>decision;
//    }
//
//    if(decision == "v" || decision == "V")
//    {
//        cout<<"              Vardas               Pavarde        Vid.       Memory Address"<<endl;
//        cout<<"---------------------------------------------------------------------------"<<endl;
//        for(auto &stud:sarasas)
//        {
//            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<
//            stud.getVidurkis()<<" "<<setw(10)<<&stud<<endl;
//        }
//    }
//    else if(decision == "m" || decision == "M")
//    {
//        cout<<"              Vardas               Pavarde        Med.       Memory Address"<<endl;
//        cout<<"---------------------------------------------------------------------------"<<endl;
//        for(auto &stud:sarasas)
//        {
//            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<
//            stud.getMediana()<<" "<<setw(10)<<&stud<<endl;
//        }
//    }
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
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<
            stud.getVidurkis()<<" "<<setw(10)<<&stud<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde        Med.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vardas()<<" "<<setw(20)<<stud.pavarde()<<" "<<setprecision(2)<<setw(10)<<
            stud.getMediana()<<" "<<setw(10)<<&stud<<endl;
        }
    }
}