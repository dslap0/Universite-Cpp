// author: Nicolas Levasseur
#include <iostream>
#include <iomanip>
using namespace std;

  void trouveSexe(char sexe[], int nbElem, char sexeRech)
  {
       /* Cette fonction vise a trouver le nombre d'occurence d'un certain
       phenomene (ici le nombre de personne d'un certain sexe) avec un compteur
       iteratif qui parcourt l'ensemble du tableau et compte chaque occurence. 
       Le programme affiche ensuite le resultat sur le terminal, accompagne d'un
       message explicatif correspondant. Le programme ne peut compter que les 
       hommes ou les femmes.
       */
       // On initialise les variables locales de la fonction
       int nbOccurences = 0;
       string message;
       
       // On trouve le nombre d'occurence du sexe recherche
       for(int i = 0; i < nbElem; i++)
       	 if(sexe[i] == sexeRech)
         nbOccurences++;
        
       // On determine si on cherchait des hommes ou des femmes
       if(sexeRech == 'M')
         message = " hommes";
       if(sexeRech == 'F')
         message = " femmes";
       
       // On montre les resultats a l'utilisateur
       cout << "Il y a " << nbOccurences << message
            << " dans le groupe." << endl;
  }

  template <class T>
  void trouveNbPlus(T tab[], int nbElem, T limite, const char message[])
  {
       /* Ce modele de fonction vise a trouver le nombre d'occurence ou un 
       participant depasse une certaine limite preetablie (par exemple, combien
       mesurent plus de 1.70 m) et affiche un message correspondant. 
       */
       // On intialise la variable locale de la fonction
       int nbPlus = 0;
       
       // On test chaque element du tableau en ajustant notre compteur
       for(int i = 0; i < nbElem; i++)
         if(tab[i] > limite)
           nbPlus++;

       cout << "Il y a " << nbPlus << message << " dans le groupe." << endl;
  }
  
  template <class T>
  void trouveMin(T tab[], int nbElem, const char message[])
  {
       /* Ce modele de fonction vise a trouver un minimum parmis les valeurs 
       d'un tableau et de retourner ce minimum a l'utilisateur accompagne d'un
       message contextuel. Pour trouver le minimum, une boucle iterative sur
       l'ensemble des valeurs du tableau compare le minimum avec la nouvelle
       valeur et effectue une substitution si la nouvelle valeur est plus
       petite que l'ancien minimum. 
       */
       // Initialisation du minimum
       T min = tab[0];
       
       // On compare le minimum avec toutes les autres valeurs possibles
       for(int i = 1; i < nbElem; i++)
         if(min > tab[i])
           min = tab[i];
       
       // On montre le minimum a l'utilisateur
       cout << message << min << endl;
  }  

  void afficher(int age[], int nbCafe[], char sexe[], float taille[], 
  int nbPers, const char message[])
  {
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     
     cout << "Contenu des 4 tableaux " << message 
          << " :\nindice      age     cafe   sexe   taille" << endl;

     for(int i = 0; i < nbPers; i++)
       cout << setw(3) << i << ") " << setw(10) << age[i] << setw(8) 
            << nbCafe[i] << setw(6) << sexe[i] << setw(10) << setprecision(2)
            << taille[i] << endl;
     cout << endl; 
  }
 
  template <class T>
  float moyenne(T tab[], int nbElem)
  { float somme = 0.0 ;
    for(int i = 0; i < nbElem ; i++)
       somme += tab[i];
  
    return somme / nbElem ;      
  }

int main()
{
    // On initialise les variables
    int age[] = { 25, 19, 41, 37, 20, 37 },
        nbCafe[] = { 3, 4, 0, 6, 3, 2 } ;
    char sexe[] = { 'F', 'M', 'F', 'F', 'M', 'F' };
    float taille[] = { 1.72, 1.84, 1.65, 1.57, 1.93, 1.85 };
    const float LIMTAILLE = 1.7;
  
    int nbPers = sizeof(age) / sizeof(int);
      
    afficher(age, nbCafe, sexe, taille, nbPers, " au debut");    
  
    cout << "Age moyen : " << setw(6) 
         << setprecision(2) << moyenne(age, nbPers) << " an(s) " << endl ;
    cout << "Consommation moyenne de cafe : " << setw(6) 
         << setprecision(2) << moyenne(nbCafe, nbPers) 
         << " tasse(s) par jour" << endl ;
      
    cout << "Taille moyenne : " << setprecision(2) 
         << moyenne(taille, nbPers) << " metre\n" << endl;
    
    // On trouve le nombre d'hommes et de femmes dans le groupe
    trouveSexe(sexe, nbPers, 'F');
    trouveSexe(sexe, nbPers, 'M');
    cout << endl;
       
    // On trouve le nombre d'occurences dont une valeur depasse une limite
    trouveNbPlus(age, nbPers, 20, " personnes de plus de 20 ans");
    trouveNbPlus(nbCafe, nbPers, 2, 
    " personnes qui boivent plus de 2 cafes par jour");
    trouveNbPlus(taille, nbPers, LIMTAILLE,
    " personnes mesurant plus de 1.70 metres");
    cout << endl;
  
    // On trouve les minimums de differents 
    trouveMin(age, nbPers, "L'age minimal (en annee) parmis le groupe est ");
    trouveMin(nbCafe, nbPers, 
    "Le minimum de cafes bu par jour par un membre du groupe est ");
    trouveMin(taille, nbPers,
    "La taille minimale (en metre) parmis le groupe est ");
  
    cout << "\nPresser la touche Enter pour quitter." << endl;
    getchar();

    return 0;
}
