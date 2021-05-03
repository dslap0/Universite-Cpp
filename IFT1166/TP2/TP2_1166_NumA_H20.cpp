// author: Nicolas Levasseur
#include <iostream>
#include <iomanip>
using namespace std;

class Employe {
  /* Cet objet a un numero d'assurance sociale et un salaire
  hebdomadaire.
  */
  private :
          string NAS;      // format "123 456 789", ex : "250 343 567"
          float  salHebdo; // exemple 1075.25

  public :
          // Constructeur a 2 parametres
          Employe(string NAS, float salHebdo){
            this->NAS = NAS;
            this->salHebdo = salHebdo;
          }
          // Constructeur a 3 parametres
          Employe(string NAS, float salHoraire, float hrsTravaille){
            this->NAS = NAS;
            salHebdo = salHoraire * hrsTravaille;
          }

          // Methode d'acces au salaire hebdomadaire
          float getSalHebdo(){
            return salHebdo;
          }
          // Methode de modification sur le salaire hebdomadaire
          void setSalHebdo(float salHebdo){
            this->salHebdo = salHebdo;
          }

          // Fonction membre d'affichage des parametres de l'objet
          void afficher(const char message[]){
            cout << message << " :\n   NAS : " << NAS 
                 << "\n   Salaire hebdomadaire : " << salHebdo 
                 << "$ par semaine\n\n";
          }
}; // fin de la classe Employe 

int main(){
  // On declare les employes
  Employe emp1("321 498 726", 987.50),                          
          emp2("135 444 321", 45.00, 20.00);
            
  // On affiche les informations du deuxième employé
  emp2.afficher("Informations du deuxieme employe");

  // On change le salaire du premier employe
  emp1.setSalHebdo(emp2.getSalHebdo() + 123.25);

  // On affiche les informations du premier employe apres modification
  emp1.afficher("Informations du premier employe (apres modifications)");
  
  return 0;
}
