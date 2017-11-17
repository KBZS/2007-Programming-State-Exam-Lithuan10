#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct receptas // struktura massiva dlja imeni bljuda i kolichestva kazhdogo produkta dlja etogo bljuda (dlja nuskaitymasa)
{
    string pvardas;
    int PR[10];
};

struct rezult // NEOBJAZATELNO struktura massiva rezultata (gde budet imja bljuda i obshaja cena vseh nuzhnyh dlja nego produktov v centah)
{
    string pvardas;
    int ckaina;
};

void nuskaitymas();
void skaiciavimai();
void spausdinimas();

int n, p;
int isviso = 0, lt, ct;

receptas PAT[100]; // glavnyj massiv chtoby schtat infu o bljudah
int K[100]; // massiv dlja cen na produkty

rezult REZ[100];

char eil[15]; // zarezerviryvaju mesto v 15 simvolov dlja imen bljud

int main()
{
    nuskaitymas();
    skaiciavimai();
    spausdinimas();
    return 0;
}

void nuskaitymas()
{
    ifstream fd("U1.txt");
    fd >> n >> p;  // schityvaju kolvo nuzhnyh produktov i kolvo bljud na odnogo cheloveka
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd >> K[i]; // schityvaju ceny na kazhdyj produkt
    }
    fd.ignore();
    for(int i=0; i<p; i++)
    {
        fd.get(eil, 15);
        PAT[i].pvardas = eil; // zapisyvaju imja v jachejku struktury glavnogo massiva
        for(int j=0; j<n; j++)
        {
            fd >> PAT[i].PR[j]; // zapisyvaju kovlo nuzhnyh produktov dlja opr. bljuda v jachejku struktury glavnogo massiva
        }
        fd.ignore();
    }
    fd.close();
}

void skaiciavimai()
{
    for(int i=0; i<100; i++)
    {
        REZ[i].ckaina = 0; // abnuljaju jachejki obshej ceny v ct struktury massiva rezultata
    }
    int kaina;
    for(int i=0; i<p; i++)
    {
        REZ[i].pvardas = PAT[i].pvardas; // zapisyvaju v jachejku struktury massiva rezultata imja opredelennogo bljuda
        for(int j=0; j<n; j++)
        {
            kaina = PAT[i].PR[j] * K[j]; // schitaju obshuju cenu v ct
            REZ[i].ckaina = kaina + REZ[i].ckaina; // =||=
        }
    }
    for(int i=0; i<p; i++)
    {
        isviso = REZ[i].ckaina + isviso; // schitaju skolko vsego ct na vse bljuda
    }
    lt = isviso/100; // skolko eto v litah
    ct = isviso%100; // skolko eto v centah
}

void spausdinimas()
{
    ofstream fr("U2rez.txt");
    for(int i=0; i<p; i++)
    {
        fr << REZ[i].pvardas << REZ[i].ckaina << endl; // vyvozhu massiv rezultata
    }
    fr << lt << " " << ct;
    fr.close();
}
