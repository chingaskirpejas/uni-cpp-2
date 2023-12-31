#include "file_generator.h"
#include "my_lib.h"
#include "functions.h"
#include "list_test.h"


void generate_files()
{
    cout<<"Kiek pazymiu tures mokinys?"<<endl;
    string paz_ans;
    cin>>paz_ans;
    cout<<"Generuoti failus (g), ar testuoti duomenu konteinerius(t)?"<<endl;
    string atsakymas;
    cin>>atsakymas;
    while (atsakymas != "G" && atsakymas != "g" && atsakymas != "T" && atsakymas != "t")
    {
        cout<<"Neteisingas pasirinkimas, bandykite dar karta"<<endl;
        cin>>atsakymas;
    }
    if(atsakymas == "G" || atsakymas == "g")
    {
        cout<<"Kuriami failai...";
        create_x(1000, stoi(paz_ans));
        create_x(10000, stoi(paz_ans));
        create_x(100000, stoi(paz_ans));
        create_x(1000000, stoi(paz_ans));
        create_x(10000000, stoi(paz_ans));
    }
    else
    {
        cout<<"Testuojamas vector tipo konteinerio veikimas"<<endl;

        run_vector_test(1000, stoi(paz_ans));
        run_vector_test(10000, stoi(paz_ans));
        run_vector_test(100000, stoi(paz_ans));
        run_vector_test(1000000, stoi(paz_ans));
        run_vector_test(10000000, stoi(paz_ans));

        cout<<"Testuojamas list tipo konteinerio veikimas"<<endl;

        run_list_test(1000, stoi(paz_ans));
        run_list_test(10000, stoi(paz_ans));
        run_list_test(100000, stoi(paz_ans));
        run_list_test(1000000, stoi(paz_ans));
        run_list_test(10000000, stoi(paz_ans));

        cout<<endl<<"Testavimas baigtas"<<endl;
    }
}


void run_vector_test(int amount, int paz_kiek)
{
    cout<<"Testuojamas failas" << amount << ".txt"<<endl;
    vector <Studentas> visi_studentai;
    visi_studentai.reserve(amount);
    //     FAILO NUSKAITYMAS
    auto start = std::chrono::high_resolution_clock::now();
    visi_studentai = read_file(amount, paz_kiek);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    vector <Studentas> studentai2(visi_studentai);
    cout << "Failo nuskaitymas uztruko " <<duration.count() << " ms" << endl;


    //      FAILO RUSIAVIMAS
    start = std::chrono::high_resolution_clock::now();

    vector <Studentas> vargsiukai;
    vargsiukai.reserve(amount);
    vector <Studentas> kietekai;
    kietekai.reserve(amount);
    // BUDAS Nr 1
    atrinkimas(visi_studentai, vargsiukai, kietekai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Masyvo rusiavimas 1 budu uztruko "<< duration.count() << " ms"<< endl;

    start = std::chrono::high_resolution_clock::now();
    // BUDAS Nr 2
    atrinkimas2(visi_studentai, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout<<"Masyvo rusiavimas 2 budu uztruko "<< duration.count() << " ms"<< endl;

    start = std::chrono::high_resolution_clock::now();
    // BUDAS Nr 3
    atrinkimas3(studentai2, vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout<<"Masyvo rusiavimas 3 budu uztruko "<< duration.count() << " ms"<< endl;


    //      RASYMAS I FAILUS
    start = std::chrono::high_resolution_clock::now();

    write_to_file(amount, vargsiukai, kietekai);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Rasymas i failus uztruko "<< duration.count() << " ms" << endl;
}



void create_x(int amount, int paz_kiek)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(1, 10);

    string kiek = to_string(amount);
    ofstream outfile(kiek+".txt");
    outfile<<"Vardas   Pavarde ";
    for(int i=0; i<paz_kiek; i++)
    {
        outfile<<"ND"<<i+1<<" ";
    }
    outfile<<"EGZ"<<endl;

    for(int i=0; i<amount-1; i++)
    {
        outfile<<"Vardas"+ to_string(i+1)+" "<<"Pavarde"+to_string(i+1)<<" ";
        for(int j=0; j<paz_kiek+1; j++)
        {
            outfile<<dist(engine)<<" ";
        }
        outfile<<to_string(dist(engine))<<endl;
    }
    outfile.close();
}

vector <Studentas> read_file(int kiekis, int nd_dydis)
{
    ifstream file("../"+to_string(kiekis) + ".txt");
    string line;

    vector <Studentas> visi_stud;
    visi_stud.reserve(kiekis);

    if(file.is_open())
    {
        getline(file, line);

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


void atrinkimas(vector <Studentas>& visi_studentai, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai)
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
void atrinkimas2(vector <Studentas>& visi_studentai, vector <Studentas>& vargsiukai)
{
    auto criteria = [](const Studentas& obj) {
        return obj.getRez() < 5.0;
    };
    auto i = std::partition(visi_studentai.begin(), visi_studentai.end(), criteria);

    vargsiukai.assign(visi_studentai.begin(), i);
    visi_studentai.erase(visi_studentai.begin(), i);

}

void atrinkimas3(vector <Studentas>& visi_studentai, vector <Studentas>& vargsiukai)
{
    auto partition_point = std::partition(visi_studentai.begin(), visi_studentai.end(), [](const Studentas& s) {
        return s.getRez() >= 5.0;
    });

    vargsiukai.insert(vargsiukai.end(), partition_point, visi_studentai.end());
    visi_studentai.resize(std::distance(visi_studentai.begin(), partition_point));
}

void write_to_file(int kiekis, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai)
{
    string kiek = to_string(kiekis);

    ofstream outfile(kiek+"out1.txt");
    outfile<<"Vardas     Pavarde   Galutinis"<<endl;

    for(const auto& studentas: vargsiukai)
    {
        outfile<<studentas.vardas()<<" "<<studentas.pavarde()<<" "<<studentas.getRez()<<endl;
    }
    outfile.close();


    ofstream outfile2(kiek+"out2.txt");
    outfile2<<"Vardas     Pavarde   Galutinis"<<endl;;

    for(const auto& studentas: kietekai)
    {
        outfile2<<studentas.vardas()<<" "<<studentas.pavarde()<<" "<<studentas.getRez()<<endl;
    }
    outfile2.close();
}


