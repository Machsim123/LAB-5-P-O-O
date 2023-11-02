#include <iostream>
#include <string.h>

using namespace std;

class Abilitate {
 char* descriere=NULL; // ex: “throws_axe”, “stops_time”, ..
 bool rara=0; //abilitatea e rara daca e detinuta de putine caractere
//initial orice abilitate e considerara rara
 void set_descriere(char *);
public:
    ///Abilitate()=default;
    Abilitate(char *v=NULL, bool b=0);
    Abilitate(const Abilitate &);
    Abilitate& operator=(const Abilitate&);
    ~Abilitate();
    friend istream& operator>>(istream&, Abilitate &);
    friend ostream& operator<<(ostream &, const Abilitate &);
    char * get_descriere();
    void change_descriere(char*);
    void change_rara(bool);
    bool get_rara();
};
