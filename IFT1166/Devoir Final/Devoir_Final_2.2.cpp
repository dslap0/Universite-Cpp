#include <iostream>
#include <string>
using namespace std;

void affiche(string str){
    // On affiche les dates de naissances correctement formatees
    // On declare les variables
    string mois = str.substr(5, 2);

    if(mois == "01")
        mois = " janvier ";
    else if (mois == "02")
        mois = " fevrier ";
    else if (mois == "03")
        mois = " mars ";
    else if (mois == "04")
        mois = " avril ";
    else if (mois == "05")
        mois = " mai ";
    else if (mois == "06")
        mois = " juin ";
    else if (mois == "07")
        mois = " juillet ";
    else if (mois == "08")
        mois = " aout ";
    else if (mois == "09")
        mois = " septembre ";
    else if (mois == "10")
        mois = " octobre ";
    else if (mois == "11")
        mois = " novembre ";
    else if (mois == "12")
        mois = " decembre ";

    cout << "La premiere personne est nee le " << str.substr(8, 2) << mois 
         << str.substr(0, 4) << endl;

}

int main(){
    // On declare des variables
    string naissance1 =  "1992-07-15",
           naissance2 =  "1991-02-14";

    affiche(naissance1);
    affiche(naissance2);

    return 0;
}
