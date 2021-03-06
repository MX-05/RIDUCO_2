#include "const.h"
#include <iostream>

# define max 100
using namespace std;

struct kitchen
{
    string tag;
    string food[max];
    float co_2[max];
    int n;
};
struct ShoppingCart
{
    string date;
    string inf;
    float co2;
    int punt;
};

/********** TABLE MANAGER *********/

// inizializza il vettore mettendo tutti i tag vuoti
void init_kitchen(kitchen Fstorage[], int n){
    for (int i=0; i<n; i++){
        Fstorage[i].tag = "";
    }
    return;
}

//visualizza la tabella
void visua_tab(kitchen table[], int n){
    int len=0;

    for (int i=0; i<n; i++){
        len = table[i].tag.length();

        cout<<' '<<alphabet[i]<<") "<<table[i].tag<<endl;
        /* |_______*/cout<<string(len/2, ' ')<<"|"<<string(len/2, '_')<<"cibo: \n";
        
        for (int j=0; j<table[i].n; j++){
            cout<<string(len, ' ')<<j+1<<". "<<table[i].food[j]<<";\n";
        }
        cout<<endl<<string(41, '-')<<endl<<endl;
    }

    return;
}

// FIXME: run and fix the bug
/*
void new_visua_tab(kitchen tab[], int n){
    
    int n_max =0;

    // scrivo tutte le categorie
    for (int i=0; i<n; i++){
        cout<<" | "<<tab[i].tag;

        if (n_max <tab[i].n)
            n_max = tab[i].n;

    }cout<<" | \n";

    // scrivo i cibi
    for (int j=0; j<n_max; j++){
        for (int i=0; i<n; i++){

            if (j<tab[i].n){
                cout<<" | "<<tab[i].food[j];

                // se il nome del cibo è più piccolo del nome della categoria, allora aggiunge degli spazi per la formattazione
                if (tab[i].food[j].length() < tab[i].tag.length())
                    cout<<string(tab[i].tag.length() -tab[i].food[j].length(), ' ');
            }
            else
                cout<<" | "<<string(tab[i].tag.length(), ' ');

        }cout<<" | \n";
    }
    
    return;
}
*/

void visua_tags(kitchen v[], int n, bool all){
    cout<<string(46, '-')<<"\nCATEGORIE: \n"<<string(46, '-')<<endl;

    for (int i=0; i<n; i++){
        cout<<' '<<i+1<<") "<<v[i].tag<<endl;
    }
    if (all)
        cout<<' '<<n+1<<") All\n"<<endl;

    return;
}

void visua_foods(string v[], int n){
    // TODO: inserire la visualizzazione verticale se < 10
    for (int i=0; i<n; i++){
        cout<<' '<<i+1<<". "<<v[i]<<";\n";
    }cout<<endl;

    return;
}

/********** LIST MANAGER *********/

void init_list (ShoppingCart list[], int &pt, int &pl, int n){
    
    pt = -1; pl = 0;
    for (int i=0; i<n; i++){
        list[i].date = ""; // TODO: write current date
        list[i].inf = "";
        list[i].co2 = 0.0;
        list[i].punt = i+1;
    }
    list[n-1].punt = -1;
    
    return;
}

int sgancia(ShoppingCart list[], int &pl, float co2, string inf){
    int old_pl = pl;

    if (pl != -1){
        list[pl].co2 = co2;
        list[pl].inf = inf;
        pl = list[pl].punt;
    }
    else
        cout<<" ! oh oh non c'è più spazio nella lista [=Г ] \n";
    
    return old_pl;
}

void intesta (ShoppingCart list[], int &pt, int &pl, float co2, string inf){
    int old_pt = pt;

    pt = sgancia(list, pl, co2, inf);
    list[pt].punt = old_pt;
    
    return;
}

void watch(ShoppingCart list[], int pt){
    if (pt == -1){
        cout<<" ! Non ci sono elementi da visualizzare [:-(]\n";
        return;
    }

    int i = pt;
    cout<<endl<<"Ecco gli elementi inseriti: \n";

    while(i != -1){
        cout<<' '<<i+1<<") "<<list[i].inf<<endl;
        i = list[i].punt;
    }

    return;
}

float emissionsCalc (ShoppingCart list[], int pt){
    float cont = 0.0;

    if (pt == -1)
        cout<<" ! Non ci sono elementi da calcolare [:-(]\n";

    int i= pt;
    while (i != -1){
        cont = cont + list[i].co2;

        i = list[i].punt;
    }

    return cont;
}