#include "Abilitate.h"

class Caracter_Joc {
 char* tip=NULL; // ex: "razboinic", “vrajitor”, ..
 Abilitate r;// =Abilitate(); //abilitatea principala a acestui caracter din joc
 int id=0; // 12
 void set_tip(char *);
public:
    Caracter_Joc() = default;
    Caracter_Joc(char*   , const Abilitate &   , int  );
    Caracter_Joc(const Caracter_Joc &);
    Caracter_Joc& operator=(const Caracter_Joc&);
    ~Caracter_Joc();
    friend istream& operator>>(istream&, Caracter_Joc &);
    friend ostream& operator<<(ostream &, const Caracter_Joc &);
    char * get_tip();
    void change_tip(char*);
    char * get_descriere2();
    void change_rara2(bool);
    bool get_rara2();
    //void change_descriere(char*);
    void afis();

};

Caracter_Joc * fct_ext(Caracter_Joc [], int , char*, int);
