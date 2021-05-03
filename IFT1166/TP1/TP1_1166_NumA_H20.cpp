// author: Nicolas Levasseur
#include <iostream>
#include <iomanip>
using namespace std;

int nbDiv(int nombre)
  {
  /* Cette fonction sert � trouver le nombre de diviseur d'un nombre
  donne en argument.
  */
  int n = 0; // On initialise le compteur de division
    
  for(int i = 1 ; i <= nombre; i++)
    if (nombre % i == 0)
      n++;
  
  return n; // On retourne le nombre de division        
}
   
int main()
{
  // On initialise les variables
  const int nb[] = {17, 20};
  int cmbDiv, j;
  
  for(int k = 0; k < 2; k++){
    j = 1;
    // On trouve le nombre de diviseurs de chaque nombre
    cmbDiv = nbDiv(nb[k]);
    // On affiche une entete pour comprendre de quel nombre on parle
    cout << "Les " << cmbDiv << " diviseurs de "
         << nb[k] << " sont : " << endl; 
    for(int i = 1; i <= nb[k]; i++){ 
      // On verifie quels entiers plus petit que le nombre sont
      // des diviseurs de ce nombre et on les montre a 
      // l'utilisateur
      if(nb[k] % i == 0){
        cout << j << ") " << setw(3) << i << endl;
        j++;
      } // end if
    } // end for used in "j)..."
    cout << endl;
    } // end for used in nb[k]
    
    cout << "Presser la touche Enter pour quitter." << endl;
    getchar();
    
    return 0;
} // end main
