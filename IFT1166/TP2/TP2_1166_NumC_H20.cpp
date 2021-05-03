/* 
    Fichier Tab_Pers.cpp
    Une version "minimale" pour un tableau des personnes
    
    A ammliorer + adapter selon vos besoins du numéro B du TP2
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std; // librairie standard

class Personne
{
   private :
      char sexe ;
      float taille, poids ;
      int numero;

   public :

    // constructeur avec définition reportée      
    Personne(char sexe, int numero, float taille, float poids);
    
    // constructeur sans paramètre dont le corps est VIDE
    Personne()
    {
    }  
    
    // Methodes d'acces a chaque parametre
    int getNumero(); // definition reportee
    float getTaille(){
      return taille;
    }
    float getPoids(){
      return poids;
    }
    char getSexe(){
      return sexe;
    }

    // Fonction membre d'affichage des parametres de la personne
    void show(){
      cout << numero << "   " << sexe << "    " << setw(6) << taille
           << " " << poids << endl;
    }
};

int Personne::getNumero()
{
    return numero;
}

Personne::Personne(char sexe, int numero, float taille, float poids)
      {
        this->sexe = sexe;
        this->numero = numero;
        this->taille = taille;
        this->poids = poids;            
      }  
 

        
    void lireRemplir(const char nomALire[], Personne pers[], int & n)
     {   
       const float PIED_EN_METRE = 0.3048,
                   LIVRE_EN_KG = 0.454;
       int numero, nbPieds, nbPouces, nbLivres;
       float taille, poids;
       char sexe;
          
       ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture

        n = 0;				
		while (aLire >> sexe >> numero >> nbPieds >> nbPouces >> nbLivres)			       
		{
               taille = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
               poids  = nbLivres * LIVRE_EN_KG ;                                
               pers[n++] = Personne(sexe, numero, taille, poids);               
		}
		aLire.close();   
	}

void montreTout(Personne pers[], int nbPers, const char message[]){
  /* On montre toutes les personnes dans un array de personnes donne. 
  */
  cout << message << "\nNumero Sexe Taille Poids" << endl;
  
  for(int i = 0; i < nbPers; i++)
    pers[i].show();
}

void tailleMin(Personne pers[], int nbPers){
  /* Cette fonction determine et affiche les informations de la plus 
  petite personne dans un array donne. 
  */

  // On initialise les variables
  int iMin = 0;
  float min = pers[0].getTaille();

  // On determine la plus petite personne
  for(int i = 1; i < nbPers; i++){
    if(pers[i].getTaille() < min){
      min = pers[i].getTaille();
      iMin = i;
    }
  }

  // On montre les informations de la plus petite personne
  cout << "Voici la personne de plus petite taille:\nNumero Sexe Taille Poids" 
       << endl;
  pers[iMin].show();
}

void poidsMaxF(Personne pers[], int nbPers){
  /* Cette fonction determine et affiche les informations de la femme la 
  plus lourde dans un array donne. 
  */

  // On initialise les variables
  int iMax;
  float max = 0;

  // On determine la femme la plus lourde
  for(int i = 0; i < nbPers; i++){
    if(pers[i].getSexe() == 'F'){
      if(pers[i].getPoids() > max){
        max = pers[i].getPoids();
        iMax = i;
      }
    }
  }

  // On montre les informations de la femme la plus lourde
  cout << "Voici la femme avec le plus grand poids:\nNumero Sexe Taille Poids" 
       << endl;
  pers[iMax].show();
}

void tailleMaxM(Personne pers[], int nbPers){
  /* Cette fonction determine et affiche les informations du plus grand 
  homme dans un array donne. 
  */

  // On initialise les variables
  int iMax;
  float max = 0;

  // On determine l'homme le plus grand
  for(int i = 0; i < nbPers; i++){
    if(pers[i].getSexe() == 'M'){
      if(pers[i].getTaille() > max){
        max = pers[i].getTaille();
        iMax = i;
      }
    }
  }

  // On montre les informations du plus grand homme
  cout << "Voici l'hommme avec la plus grande taille:\nNumero Sexe Taille Poids" 
       << endl;
  pers[iMax].show();
}

void poidsMoyF(Personne pers[], int nbPers){
  /* Cette fonction trouve et affiche le poids moyen des femmes d'un 
  array donne.
  */
  // On intialise les variables
  float somme = 0,
        moy;

  // On trouve la moyenne pour le poids chez les femmes
  for(int i = 0; i < nbPers; i++)
    if(pers[i].getSexe() == 'F')
      somme += pers[i].getPoids();
  moy = somme / nbPers;

  // On affiche le poids moyen chez les femmes
  cout << "Le poids moyen chez les femmes est de: " << moy << endl;
}
    
void tailleMoyM(Personne pers[], int nbPers){
  /* Cette fonction trouve et affiche la taille moyenne des hommes d'un 
  array donne.
  */
  // On intialise les variables
  float somme = 0,
        moy;

  // On trouve la moyenne pour la taille chez les hommes
  for(int i = 0; i < nbPers; i++)
    if(pers[i].getSexe() == 'F')
      somme += pers[i].getTaille();
  moy = somme / nbPers;

  // On affiche la taille moyenne chez les hommes
  cout << "La taille moyenne chez les hommes est de: " << moy << endl;
}

template <class T>
void permuter(T &elem1, T &elem2){
  /* Cette fonction echange la position de deux objets dans un array.
  */
  // On initialise les variables
  T temp;

  // On echange les positions des elements
  temp = elem1;
  elem1 = elem2;
  elem2 = temp;
}

int partitionner(Personne pers[], int debut, int fin){ 
  // On initialise les variables
  int debutDepart = debut;
  int valPivot = pers[debut].getNumero();

  // On classe les elements par rapport au pivot jusqu'a ce qu'ils soient tous
  // classes
  do {
    while (debut <= fin && pers[debut].getNumero() <= valPivot)
      debut++;
	  while (pers[fin].getNumero() > valPivot)
      fin--;

		if (debut < fin)
		  permuter(pers[debut], pers[fin]);

	  }	while (debut <= fin);

	  permuter(pers[debutDepart], pers[fin]);
	  return fin;
}

void tri(Personne pers[], int debut, int fin){
  /* Cette fonction utlise l'algorithme quicksort afin de trier les 
  personnes par numero croissant. 
  */
  // On trie par recursion jusqu'a ce que le debut et la fin soit confondus
  if(debut < fin){
    // On initialise les variables (on trouve l'indice du pivot)
    int iP = partitionner(pers, debut, fin);
    // On trie de chaque cote du pivot
    tri(pers, debut, iP - 1);
    tri(pers, iP + 1, fin);
  }
}

void recherche(Personne pers[], int rech[], int nbPers, int nbRech){
  /* Cette fonction utilise la recherche dichotomique sur un tableau en 
  ordre croissant pour trouver et afficher les informations des 
  personnes avec certains numeros. 
  */
  // On initialise les variables
  int iDebut, iFin, iMilieu;
  bool premier = true;

  // On recherche les indices potentiels des personnes avec certains numeros
  for(int i = 0; i < nbRech; i++){
    // On assigne les variables
    iDebut = 0;
    iFin = nbPers - 1;
    iMilieu = (iFin + iDebut) / 2;

    while(rech[i] != pers[iMilieu].getNumero() && iFin - iDebut > 1){
      // On redefinit l'indice du milieu
      iMilieu = (iFin + iDebut) / 2;
      
      // On determine dans quelle portion de l'array le numero est contenu
      if(pers[iMilieu].getNumero() > rech[i])
        iFin = iMilieu;
      else
        iDebut = iMilieu;
    } // end while( && )

    // On regarde si on doit montrer les informations de la derniere personne 
    // evaluee
    if(rech[i] == pers[iMilieu].getNumero()){
      if(premier == true){
        // On affiche l'entete si c'est le premier numero trouve
        premier = false;
        cout << "La ou les personnes ayant le ou les numeros recherches sont:"
             << "\nNumero Sexe Taille Poids" << endl;
      } // end if(premier == true)
      pers[iMilieu].show();
    } // end if(rech[i] == pers[i].getNumero())
  } // end for

  // On verifie si on a trouve au moins une correspondance
  if(premier == true)
    cout << "Aucune personne n'avait un numero recherche." << endl;
}

void fichierF(Personne pers[], int nbPers){
  /* Cette fonction entre les informations de toutes les femmes en ordre 
  dans un fichier intitule Femmes.txt.
  */
  // On declare le fichier texte
  ofstream femmes;

  // On cree le fichier et son entete
  femmes.open("Femmes.txt");
  femmes << "Ce fichier contient les informations des femmes contenues dans " 
         << "imp_h20.txt\nNumero Sexe Taille Poids" << endl;

  // On met les informations de toutes les femmes dans le fichier
  for(int i = 0; i < nbPers; i++)
    if(pers[i].getSexe() == 'F')
      femmes << pers[i].getNumero() << "   " << pers[i].getSexe() << "    " 
              << setw(6) << pers[i].getTaille() << " " << pers[i].getPoids() 
              << endl;
}
  
int main() {
 // On declare nos variables
 const int MAX_PERS = 25;
 Personne pers[MAX_PERS];
 int nbPers,
     numeroRech[] = {4148, 5477, 9876};
 
 lireRemplir("imp_h20.txt",pers, nbPers);
 cout << "On a lu les infos de " << nbPers << " personnes\n";
 
 // On montre toutes les informations des personnes lues
 montreTout(pers, nbPers, "Voici le tableau des personnes lues:");
 cout << endl;

 // On trouve la plus petite personne
 tailleMin(pers, nbPers);
 cout << endl;
 
 // On trouve la femme la plus lourde et l'homme le plus grand
 poidsMaxF(pers, nbPers);
 tailleMaxM(pers, nbPers);
 cout << endl;

 // On affiche la moyenne de poids chez les femmes et la moyenne de taille 
 // chez les hommes
 poidsMoyF(pers, nbPers);
 tailleMoyM(pers, nbPers);
 cout << endl;

 // On trie et on montre les personnes par ordre de numero croissant
 tri(pers, 0, nbPers - 1);
 montreTout(pers, nbPers, "Voici le tableau des personnes trie:");
 cout << endl;

 // On cherche les informations de certaines personnes
 recherche(pers, numeroRech, nbPers, 3);
 cout << endl;

 // On cree le fichier pour les femmes
 fichierF(pers, nbPers);

 return 0;
}