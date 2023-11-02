#include <iostream>
#include <string.h>
#include "Caracter_Joc.h"

using namespace std;

void Caracter_Joc::set_tip(char *v)
{
    if(v==NULL)
        tip=NULL;
    else
    {
        tip=new char[strlen(v)+1];
        strcpy(tip,v);
    }
}

Caracter_Joc::Caracter_Joc(char* v , const Abilitate & ab , int aidi ):r(ab),id(aidi)
{
    set_tip(v);
}

Caracter_Joc::Caracter_Joc(const Caracter_Joc &j):r(j.r), id(j.id)
{
    set_tip(j.tip);
}

Caracter_Joc& Caracter_Joc::operator=(const Caracter_Joc &j)
{
    r=j.r;
    set_tip(j.tip);
    id=j.id;
    return *this;
}

Caracter_Joc::~Caracter_Joc()
{
    delete [] tip;
}

/*friend*/ istream& operator>>(istream & dev, Caracter_Joc &j)
{
    char aux[200];
    if(j.tip!=NULL)
    {
        delete [] j.tip;
        j.tip=NULL;
    }
    cout<<"Tip: ";
    dev>>aux;
    cin>>j.r;
    cout<<"Id: ";
    dev>>j.id;
    j.set_tip(aux);
    return dev;
}

/*friend*/ ostream& operator<<(ostream &dev, const Caracter_Joc &j)
{
    dev<<"Tip: "<<j.tip<<endl;
    cout<<j.r;
    dev<<"Id: "<<j.id<<endl;
    return dev;
}

char * Caracter_Joc::get_tip()
{
    return tip;
}

void Caracter_Joc::change_tip(char* ctip)
{
    set_tip(ctip);
}

char * Caracter_Joc::get_descriere2()
{
    return r.get_descriere();
}

void Caracter_Joc::change_rara2(bool nou_rar)
{
    r.change_rara(nou_rar);
}

bool Caracter_Joc::get_rara2()
{
    return r.get_rara();
}

Caracter_Joc * fct_ext(Caracter_Joc vect[], int nr, char* desc, int nr_aparitii)
{
    for(int i=0; i<nr; i++)
    {
        if(strcmp(vect[i].get_descriere2(),desc)==0)
            nr_aparitii--;
    }
    if(nr_aparitii<=0)
        {
            for(int i=0; i<nr; i++)
                if(strcmp(vect[i].get_descriere2(),desc)==0)
                    vect[i].change_rara2(1);
        }
    else
        for(int i=0; i<nr; i++)
            if(strcmp(vect[i].get_descriere2(),desc)==0)
                vect[i].change_rara2(0);
    return vect;
}

void Caracter_Joc::afis()
{
    cout<<get_descriere2()<<" "<<get_rara2()<<endl;
}
