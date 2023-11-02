#include "Caracter_Joc.h"

int main()
{

    /*Abilitate x("arunca",0),y,z(x);
    ///cout<<x<<z;
    y=z;
    ///cout<<y;
    ///cout<<y.get_descriere();
    y.change_descriere("opreste");
    ///cout<<y;
    ///cout<<y.get_descriere();


    Caracter_Joc xx,yy("razboinic",y,12);
    ///cout<<yy;
    xx=yy;
    Caracter_Joc zz(yy);
    ///cout<<xx;
    ///cout<<zz;
    ///cout<<zz.get_tip();
    zz.change_tip("vrajitor");
    cout<<zz;
    //nu merge cout<<zz.get_descriere();*/
    int n;
    cout<<"Nr: ";
    cin>>n;
    Caracter_Joc* vect;
    int nr;
    char desc[200];
    vect=new Caracter_Joc[n];
    for(int i=0; i<n; i++)
        cin>>vect[i];
    cout<<endl<<endl;
    for(int i=0; i<n; i++)
        vect[i].afis();
    cout<<endl<<endl;
    cout<<"descriere? ";
    cin>>desc;
    cout<<"aparitii? ";
    cin>>nr;
    vect=fct_ext(vect, n, desc, nr);
    for(int i=0; i<n; i++)
        vect[i].afis();
    return 0;
}
