#include "my_lib.h"
#include "functions.h"


void read_file(int choice)
{
    if(choice == 1)
    {
        parse_file("../10000.txt");
    }
    else
    {
        parse_file("../100000.txt");
    }
}

void parse_file(string const& filename)
{

    ifstream file(filename);
    string line;
    int nd_dydis;
    if(file.is_open())
    {
        vector <Studentas> studentai;
        // read first line to determine how many ND a student has
        if(getline(file, line))
        {
            istringstream iss(line);
            string stulp;
            vector <string> stulpeliai;

            while (iss>>stulp)
            {
                stulpeliai.push_back(stulp);
            }

            nd_dydis = stulpeliai.size()-3;
        }
        while(getline(file, line))
        {
            Studentas laik;
            istringstream iss(line);
            string stulp;
            vector <string> stulpeliai;
            while (iss>>stulp)
            {
                stulpeliai.push_back(stulp);
            }

            laik.setVardas(stulpeliai[0]);
            laik.setPavarde(stulpeliai[1]);
            vector<double> pazymiai;
            for(int i=2; i<nd_dydis; i++)
            {
                pazymiai.push_back(stoi(stulpeliai[i]));
            }
            laik.setEgz(stoi(stulpeliai[stulpeliai.size()-1]));
            laik.setPazymiai(pazymiai);
            studentai.push_back(laik);
            laik.clearPazymiai();
        }
        file.close();
        printas(studentai);
    }
    else
    {
        cout<<"Could not open the file";
    }

}


