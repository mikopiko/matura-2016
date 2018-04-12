#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

    fstream plik;
    plik.open("dane_6_2.txt", ios::in); //wczytanie pliku
    if(plik.good()==false) //zabezpieczenie przed brakiem pliku
    {
        cout<<"plik nie istnieje padawanie";
        exit(0);
    }
    string linia; //linia czyli pojedyncze slowo
    int nrlinii=1;
    int k;
    while(plik >> linia >> k)
    {
        k=k%26;
        for(int i=0; i<=linia.length(); i++)
        {
            if(linia[i]>=65 && linia[i]<=90-k) linia[i]=int(linia[i])+k; //wielkie liter
            else if(linia[i]>=91-k && linia[i]<=90) linia[i]=int(linia[i])-26+k; // wielkie litery
        }

        cout<<linia<<" , "<<k<<endl;
        nrlinii++;
    }
    plik.close(); //zamykamy beng
    return 0;
}
