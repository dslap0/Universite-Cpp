/* Fichier tp1_1166_numC_H20.cpp pour le numéro C du Tp1 IFT 1166

   Numéro C du TP1 : 10 points
        
   Ajouter des fonctions et leurs appels afin de :
   1. afficher le contenu de ces 4 tableaux avant le tri;
   2. rechercher et afficher les résultats de la
      recherche des personnes ayant de numéros suivants :
            2233, 4177, 9876
      par la recherche séquentielle dans le tableau 
      des numéros non triés
        
   3. déterminer et afficher toutes les informations
         a) d'une personne ayant la taille la plus grande
         b) d'une personne ayant le poids le plus lourd
   4. calculer et afficher
         a) la taille moyenne des femmes
         b) le poids moyen des hommes
   5. trier (avec le tri par sélection) les personnes selon leurs 
      numéros et afficher le contenu de ces 4 tableaux
      après le tri;                     
   6. rechercher et afficher les résultats de la
      recherche des personnes ayant de numéros suivants :
            2233, 4177, 9876  
      par la recherche séquentielle dans le tableau des numéros triés
                           

    Critères de correction :
        6 x 1 point pour le bon fonctionnement 
        4 points pour la qualité du code
             
    Total de 10 points         
*/

// author: Nicolas Levasseur
#include <iostream>  // pour entrée-sortie  cin, cout
#include <iomanip>   // pour le formatage
#include <fstream>   // pour les fichiers


using namespace std; // librairie standard

   /* cette fonction est expliquée en classe :
      Elle permet de lire le fichier à partir de son nom,
      de remplir les 4 tableaux et de transmettre via
      pointeur le nombre de personnes lues.
   */    
      
    
    void lireRemplir(const char nomALire[], int numero[], char sexe[], 
                       float taille[], float poids[], int *p)
     {   
       const float PIED_EN_METRE = 0.3048,
                   LIVRE_EN_KG = 0.454;
       int nbPieds, nbPouces, nbLivres;
   
        ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
		   	   
	    int n = 0; // initialiser le compteur
				
		while (aLire >> sexe[n] >> numero[n] >> nbPieds >> nbPouces >> nbLivres)			       
		{
               taille[n] = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
               poids[n]  = nbLivres * LIVRE_EN_KG ;                                
               n++;
		}
		aLire.close();   
		*p = n ;
	}

  void afficherTab(int numero[], char sexe[], float taille[], float poids[],
    const int nbPers, const char message[])
  {
    /* Cette fonction tente de montrer a l'utilisateur les caracteristiques de 
    chaque utilisateur un a la suite de l'autre. 
    */
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    // On montre l'entete a l'utilisateur
    cout << "Contenu des 4 tableaux " << message << ":\n"
         << "      numero  poids  sexe   taille" << endl;

    // On montre chaque element de chaque tableau avec les elements qui leur 
    // sont associes dans les autres tableau
    for(int i = 0; i < nbPers; i++)
      cout << setw(3) << i + 1 << ") " << setw(6) << numero[i] << setw(8) 
           << setprecision(2) << poids[i] << setw(5) << sexe[i] << setw(9) 
           << setprecision(2) << taille[i] << endl;
    
    cout << endl;
  }

  void rechercheNumero(int numero[], char sexe[], float taille[], float poids[], 
    const int nbPers, const int numeroRech[], const int nbNumeroRech)
  {
    /* Cette fonction vise a montrer a l'utilisateur les personnes possedant un
    certain numero ainsi que leurs informations. 
    */
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    cout << "Voici les utilisateurs recherches: " << endl;
    
    // On cherche element par element le plus petit
    for(int j = 0; j < nbNumeroRech; j++)
      for(int i = 0; i < nbPers; i++)
        if(numero[i] == numeroRech[j])
          cout << setw(3) << i + 1 << ") " << setw(6) << numero[i] << setw(8) 
               << setprecision(2) << poids[i] << setw(5) << sexe[i] << setw(9) 
               << setprecision(2) << taille[i] << endl;
    
    cout << endl;
  }
  
  void rechercheMax(int numero[], char sexe[], float tabAnalyser[], float 
    tabInfo[], const int nbPers, const char message[])
  {
    /* Cette fonction vise a montrer a l'utilisateur les personnes avec le
    poids ou la taille maximum et afficher toutes les informations associees a
    celle-ci.
    */
    // On initialize le maximum a la premiere valeur possible et son indice
    int iMax = 0;
    float max = tabAnalyser[0];
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    // On parcourt tous les elements du tableau en les comparant avec le
    // maximum et on le redefinit si l'element est plus grand
    for(int i = 1; i <= nbPers; i++){
      if(tabAnalyser[i] > max){
        max = tabAnalyser[i];
        iMax = i;
      } // end if
    } // end for
  
    cout << "La personne la plus " << message << "est :\n" << setw(6) 
         << numero[iMax] << setw(8) << setprecision(2) << tabAnalyser[iMax]
         << setw(5) << sexe[iMax] << setw(9) << setprecision(2) 
         << tabInfo[iMax] << endl;
  } 
  
  void moySousGroupe(float tab[], char sexe[], const char compare, const int
    nbPers, const char message[])
  {
    /* Cette fonction trouve la moyenne d'un sous-groupe forme dans un array
    et la retourne a l'utilisateur. 
    */
    float somme = 0, moyenne;
    int nElemParcouru = 0;
    char preMessage;
    
    for(int i = 0; i < nbPers; i++){
      if(sexe[i] == compare){
        somme += tab[i];
        nElemParcouru++;
      } // end if
    } // end for
    
    moyenne = somme / nElemParcouru;
    
    cout << "La moyenne " << message << "est de:\n" << moyenne << endl;
  }
  
  template <class T>
  void echanger(T tab[], int i, int j)
  {
    T temp;
  
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
  }
  
  void triSelection(int numero[], char sexe[], float taille[], float poids[],
  const int nbPers)
  {
    /* Cet algorithme tri les elements d'un tableau grace a l'algorithme de tri
    par selection en modifiant directement les arrays d'origine.
    */
    // Ces boucles comparent chaque element avec le suivant et determinent le
    // plus petit des deux.
    for(int i = 0; i < nbPers - 1; i++){      
      for(int j = i + 1; j < nbPers; j++){
        if(numero[j] < numero[i])
          echanger(numero, i, j);
          echanger(sexe, i, j);
          echanger(taille, i, j);
          echanger(poids, i, j);
      } // end for(j)
    } // end for(i)
  }
     
int main()
{
  // Déclaration de 4 tableaux et du nombre de personnes lues
  // qui est aussi le nombre d'éléments de ces 4 tableaux
  const int MAX_PERS = 25, nbNumeroRech = 3;
  int nbPers;
  int numero[MAX_PERS], numeroRech[nbNumeroRech] = {2233, 4177, 9876};
  char sexe[MAX_PERS];
  float taille[MAX_PERS], poids[MAX_PERS];
  
  lireRemplir("imp_h20.txt", numero, sexe, taille, poids, &nbPers);
  cout << "On vient de lire les informations de " << nbPers << " personnes\n\n"
       << endl;

  // On montre une première fois le tableau
  afficherTab(numero, sexe, taille, poids, nbPers, "au debut ");
  
  // On cherche les 3 numeros dans la population
  rechercheNumero(numero, sexe, taille, poids, nbPers, numeroRech,
    nbNumeroRech);
  
  // On trouve les maximums de grandeur et de poids
  rechercheMax(numero, sexe, taille, poids, nbPers, "grande ");
  rechercheMax(numero, sexe, poids, taille, nbPers, "lourde ");
  cout << endl;
  
  // On fait des moyennes de certains parametres selon le sexe
  moySousGroupe(taille, sexe, 'F', nbPers, "de taille au sein des femmes ");
  moySousGroupe(poids, sexe, 'M', nbPers, "de poids au sein des hommes ");
  cout << endl;
  
  // On modifie les arrays pour qu'ils soient en ordre croissant de numero
  triSelection(numero, sexe, taille, poids, nbPers);
  
  // On montre le tableau trie
  afficherTab(numero, sexe, taille, poids, nbPers, "a la fin ");
  
  // On trouve les memes numeros que precedemment
  rechercheNumero(numero, sexe, taille, poids, nbPers, numeroRech,
    nbNumeroRech);
  
  cout << "\nPresser la touche Enter pour quitter." << endl;
  getchar();
  
  return 0;
}
