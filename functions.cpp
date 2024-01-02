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
}

void printas_list(list<Studentas>& sarasas)
{
    sarasas.sort(pagal_varda);
    for(auto& studentas : sarasas)
    {
        cout<<studentas;
    }
}