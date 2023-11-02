#include <iostream>
#include <string.h>

#include "Abilitate.h"

using namespace std;

void Abilitate::set_descriere(char *v)
{
    if(v==NULL)
        descriere=NULL;
    else
    {
        descriere=new char[strlen(v)+1];
        strcpy(descriere,v);
    }
}

Abilitate::Abilitate(char *v, bool b)
{
    set_descriere(v);
    rara=b;
}

Abilitate::Abilitate(const Abilitate &ab)
{
    set_descriere(ab.descriere);
    rara=ab.rara;
}

Abilitate& Abilitate::operator=(const Abilitate &ab)
{
    set_descriere(ab.descriere);
    rara=ab.rara;
    return *this;

}

Abilitate::~Abilitate()
{
    delete [] descriere;
}

/*friend*/ istream& operator>>(istream & dev, Abilitate &ab)
{
    char aux[200];
    if(ab.descriere!=NULL)
    {
        delete [] ab.descriere;
        ab.descriere=NULL;
        ab.rara=0;
    }
    cout<<"Descriere: ";
    dev>>aux;
    cout<<"Rara? ";
    dev>>ab.rara;
    ab.set_descriere(aux);
    return dev;
}

/*friend*/ ostream& operator<<(ostream & dev, const Abilitate &ab)
{
    dev<<"Descriere: "<<ab.descriere<<endl;
    dev<<"Rara? "<<ab.rara<<endl;
    return dev;
}

char * Abilitate::get_descriere()
{
    return descriere;
}

void Abilitate::change_descriere(char* desc)
{
    set_descriere(desc);
}

void Abilitate::change_rara(bool nou_rar)
{
    rara=nou_rar;
}

bool Abilitate::get_rara()
{
    return rara;
}
