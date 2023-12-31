#include "list_test.h"


void run_list_test(int amount, int paz_kiek)
{
    cout<<"Testuojamas failas" << amount << ".txt"<<endl;

    //     FAILO NUSKAITYMAS
    auto start = std::chrono::high_resolution_clock::now();
    list <Studentas> visi_studentai = read_file_list(amount, paz_kiek);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    list <Studentas> stud2(visi_studentai);
    cout << "Failo nuskaitymas uztruko " <<duration.count() << " ms" << endl;


    //      FAILO RUSIAVIMAS
    start = std::chrono::high_resolution_clock::now();

    list <Studentas> vargsiukai;
    list <Studentas> kietekai;

    // BUDAS Nr 1
    list_atrinkimas(visi_studentai, vargsiukai, kietekai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Masyvo rusiavimas 1 budu uztruko "<< duration.count() << " ms"<< endl;

    start = std::chrono::high_resolution_clock::now();
    // BUDAS Nr 2
    list_atrinkimas2(visi_studentai, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout<<"Masyvo rusiavimas 2 budu uztruko "<< duration.count() << " ms"<< endl;

    start = std::chrono::high_resolution_clock::now();
    // BUDAS Nr 3
    list_atrinkimas3(stud2, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout<<"Masyvo rusiavimas 3 budu uztruko "<< duration.count() << " ms"<< endl;



    //      RASYMAS I FAILUS
    start = std::chrono::high_resolution_clock::now();

    write_list_to_file(amount, vargsiukai, kietekai);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Rasymas i failus uztruko "<< duration.count() << " ms" << endl;
}

list<Studentas> read_file_list(int kiekis, int nd_dydis)
{
    ifstream file("C:\\Users\\Daniilas\\CLionProjects\\uni_cpp\\cmake-build-debug\\"+to_string(kiekis) + ".txt");
    string line;

    list<Studentas> visi_stud;

    if(file.is_open())
    {

        getline(file, line);

        while(getline(file, line))
        {
            Studentas laik;
            istringstream iss(line);
            string stulp;
            vector<string> stulpeliai;
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
            laik.setPazymiai(pazymiai);
            laik.setEgz(std::stod(stulpeliai[stulpeliai.size()-1]));
            laik.setRez();
            visi_stud.push_back(laik);
            laik.clearPazymiai();
        }
        file.close();

    }
    else
    {
        cout<<"Could not open the file"<<endl;
    }
    return visi_stud;
}

void list_atrinkimas(list<Studentas>& visi_studentai, list<Studentas>& vargsiukai, list<Studentas>& kietekai)
{
    for(const auto& studentas: visi_studentai)
    {
        if (studentas.getRez() < 5.0)
        {
            vargsiukai.push_back(studentas);
        } else
        {
            kietekai.push_back(studentas);
        }
    }
}

void list_atrinkimas2(list <Studentas>& visi_stud, list <Studentas>& vargsiukai)
{
    auto criteria = [](const Studentas& obj){
        return obj.getRez() <5.0;
    };

    std::remove_copy_if(visi_stud.begin(), visi_stud.end(), std::back_inserter(vargsiukai), criteria);

    visi_stud.erase(remove_if(visi_stud.begin(), visi_stud.end(), criteria), visi_stud.end());
}

void list_atrinkimas3(list <Studentas>& visi_studentai, list <Studentas>& vargsiukai)
{
    for(auto i = visi_studentai.begin(); i != visi_studentai.end();) {
        if (i->getRez() < 5.0) {
            vargsiukai.push_back(*i);
            i = visi_studentai.erase(i);
        } else {
            ++i;
        }
    }
}

void write_list_to_file(int kiekis, list<Studentas>& vargsiukai, list<Studentas>& kietekai)
{
    string kiek = to_string(kiekis);

    ofstream outfile(kiek+"out1.txt");
    outfile<<"Vardas     Pavarde   Galutinis";

    for(const auto& studentas: vargsiukai)
    {
        outfile<<studentas.vardas()<<" "<<studentas.pavarde()<<" "<<studentas.getRez()<<endl;
    }
    outfile.close();


    ofstream outfile2(kiek+"out2.txt");
    outfile2<<"Vardas     Pavarde   Galutinis";

    for(const auto& studentas: kietekai)
    {
        outfile2<<studentas.vardas()<<" "<<studentas.pavarde()<<" "<<studentas.getRez()<<endl;
    }
    outfile2.close();
}