#include <iostream>

using namespace std;

// On prends pour acquis que la classe Employe a deja les fonctions
// membres demandees, et que la liste a ete faite comme au numero 
// precedent, avec tous les attributs (ex: sexe, numero, etc.)
// appartenant a l'element emp qui est de classe Employe.

void affiche(Pointeur liste, const char sexe, const int numero){
    // On declare les variables
    int compteur = 0;

    while(liste){
        if(liste->emp.get_sexe() == sexe){
            compteur++;
            if(compteur == numero)
                liste->emp.affiche();
        }
        liste = liste->suivant;
    }
}

void permute(Pointeur liste, const int i1, const int i2){
    // On declare les variables
    int compteur = 0;
    Pointeur listei1;
    Employe temp;

    while(liste){
        compteur++;
        if(compteur == i1)
            listei1 = liste;
        else if(compteur == i2){
            temp = liste->emp;
            liste->emp = listei1->emp;
            listei1->emp = temp;
            break;
        }

    liste = liste->suivant;
    }
}

int main(){
    // On aurait ici toutes les etapes pour creer la liste

    affiche(liste, 'F', 4);
    affiche(liste, 'M', 12);

    permute(liste, 1, 5);

    return 0;
}
