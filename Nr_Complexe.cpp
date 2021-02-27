// Nr_Complexe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
1. Sa se proiecteze si sa se implementeze o clasa asociata numerelor complexe. Clasa va
contine supraancarcarea operatorului de atribuire, a principalilor operatori aritmetici,
precum si a operatorului ~ pentru operatia de calcul a modulului unui numar complex. De
asemenea, se va supraancarca operatorul ^ pentru operatia de ridicre a unui numar
complex la o putere intreaga. In plus, clasa trebuie sa posede o functie de afisare, precum
si constructori care sa permita urmatoarea secventa:
 complex z1; // z1 = 0+0i
 complex z2(5); // z2 = 5+0i 
 complex z3(2, 3); // z3 = 2+3i
 complex z4 = z2;
*/

#include <iostream>
#include <math.h>
using namespace std;


class Nr_complex
{
private:
    int nr_real;
    int nr_imaginar;
public:
    Nr_complex(); //prototipul unei constructorului implicit
    Nr_complex(int, int); //prototipul unui constructor general
    Nr_complex(Nr_complex&); //prototipul constructorului de copiere
    //referinta dupa.
    ~Nr_complex(); //prototipul destructorului general
    Nr_complex adunare2(Nr_complex& z2);
    Nr_complex scadere2(Nr_complex& z2);
    //adunare2 si scadere2 sunt in cadrul clasei
    void afisare();
    friend Nr_complex adunare(Nr_complex&, Nr_complex&);
    friend Nr_complex scadere(Nr_complex&, Nr_complex&);
    friend Nr_complex inmultire(Nr_complex&, Nr_complex&);
    friend Nr_complex impartire(Nr_complex&, Nr_complex&);
    friend Nr_complex putere(Nr_complex&, int);
    friend float modul(Nr_complex&);
    

};

Nr_complex::Nr_complex()
{
    nr_real = 0;
    nr_imaginar = 0;
    //in constructor initializez valorile elementelor continute de clasa
}

Nr_complex::Nr_complex(int a, int b = 0)
{
    this->nr_real = a;
    this->nr_imaginar = b;
    //this este un parametru ascuns care se refera la obiectul curent
}

Nr_complex::Nr_complex(Nr_complex& z)
{
    this->nr_real = z.nr_real;
    this->nr_imaginar = z.nr_imaginar;
    //nr complex pe care l-am primit il egalez cu obiectul z care exista
}

Nr_complex::~Nr_complex()
{
    this->nr_real = 0;
    this->nr_imaginar = 0;
    //this e optional
}

void Nr_complex::afisare() 
{ 
    if (nr_imaginar == 0)
        cout << nr_real << endl;
    else
        cout << nr_real << " + "<<nr_imaginar<<"i"<<endl; 
}

Nr_complex Nr_complex::adunare2(Nr_complex& z2)
{
    Nr_complex z3;
    z3.nr_real = this->nr_real + z2.nr_real;
    z3.nr_imaginar = this->nr_imaginar + z2.nr_imaginar;
    return z3;
}

Nr_complex Nr_complex::scadere2(Nr_complex& z2)
{
    Nr_complex z3;
    z3.nr_real = this->nr_real - z2.nr_real;
    z3.nr_imaginar = this->nr_imaginar - z2.nr_imaginar;
    return z3;

}

Nr_complex adunare(Nr_complex &z1, Nr_complex &z2)
{
    Nr_complex z3;
    z3.nr_real = z1.nr_real + z2.nr_real;
    z3.nr_imaginar = z1.nr_imaginar + z2.nr_imaginar;
    return z3;
}

Nr_complex scadere(Nr_complex& z1, Nr_complex& z2)
{
    Nr_complex z3;
    z3.nr_real = z1.nr_real - z2.nr_real;
    z3.nr_imaginar = z1.nr_imaginar - z2.nr_imaginar;
    return z3;
}

Nr_complex inmultire(Nr_complex& z1, Nr_complex& z2)
{
    Nr_complex z3;
    z3.nr_real = z1.nr_real*z2.nr_real - z1.nr_imaginar*z2.nr_imaginar;
    z3.nr_imaginar = z1.nr_real*z2.nr_imaginar + z1.nr_imaginar*z2.nr_real;
    return z3;
}

Nr_complex impartire(Nr_complex& z1, Nr_complex& z2)
{
    Nr_complex z3;
    z3.nr_real = (z1.nr_real * z2.nr_real + z1.nr_imaginar * z2.nr_imaginar) / (z2.nr_real * z2.nr_real + z2.nr_imaginar * z2.nr_imaginar);
    z3.nr_imaginar = (z1.nr_imaginar * z2.nr_real - z1.nr_real * z2.nr_imaginar) / (z2.nr_real * z2.nr_real + z2.nr_imaginar * z2.nr_imaginar);
    return z3;
}

Nr_complex putere(Nr_complex& z1, int exponent)
{
    Nr_complex z3(z1);
    if (exponent == 0)
    {
        z3.nr_real = 1;
        z3.nr_imaginar = 0;
        return z3;
    }
    if (exponent == 1)
    {
        /*z3.nr_real = z1.nr_real;
        z3.nr_imaginar = z1.nr_imaginar;
        return z3;
        */
        return z1;
    }
    for (int i = 2; i <= exponent; i++)
    {
        z3 = inmultire(z3, z3);;
    }
    return z3;
}

float modul(Nr_complex& z1)
{
    float valoare;
    valoare =sqrt(z1.nr_real * z1.nr_real + z1.nr_imaginar * z1.nr_imaginar);
    return valoare;
}

int main()
{
    Nr_complex z1(3, 2), z2(1, 2), z3(1, 3);
    Nr_complex z_adunare, z_scadere, z_inmultire, z_impartire, z_putere;
    /*z_adunare = adunare(z1, z2);
    z_adunare.afisare();
    z_scadere = scadere(z1, z2);
    z_scadere.afisare();
    z_inmultire = inmultire(z2, z3);
    z_inmultire.afisare();
    z_impartire = impartire(z1, z2);
    z_impartire.afisare();
    z_putere = putere(z2, 2);
    z_putere.afisare();
    cout << modul(z1) << endl;
    */
    z_adunare = z1.adunare2(z2);
    z_adunare.afisare();
    z_scadere = z1.scadere2(z2);
    z_scadere.afisare();
    return 0;
}


