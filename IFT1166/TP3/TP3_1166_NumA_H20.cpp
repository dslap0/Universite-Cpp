#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std; // librairie standard

class Employe
{
  private :
    char sexe ;
    float salHebdo;
    int numero;

  public :
    // constructeur avec définition reportée      
    Employe(char sexe, int numero, float heures, float salaire){
      this->sexe = sexe;
      this->numero = numero;
      salHebdo = heures * salaire;  
    }
    
    // constructeur sans paramètre dont le corps est VIDE
    Employe()
    {
    }
    
    // Methodes d'acces a chaque parametre
    int getNumero(){
      return numero;
    }
    int getSalHebdo(){
      return salHebdo;
    }
    char getSexe(){
      return sexe;
    }

    // On met des méthodes de modification
    void setSexe(char sexe){
      this->sexe = sexe;
    }
    void setSalHebdo(float salHebdo){
      this->salHebdo = salHebdo;
    }

    friend ostream& operator << (ostream& sortie, const Employe& unePers){
      sortie.setf(ios::fixed);
      sortie.setf(ios::showpoint);
    
      sortie << setw(2) << unePers.sexe << setw(5) << unePers.numero << setw(8)
             << setprecision(2) << unePers.salHebdo << endl;
      
    return sortie;       
    }
};

struct Element{
  Employe emp ;
  Element * suivant ;
};

typedef Element * Pointeur;

void lireRemplir(const char nomALire[], Pointeur& liste, Pointeur & dernier){
  int numero;
  float heures, salaire, salHebdo;
  char sexe;

  liste = NULL;
          
  ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
				
	while (aLire >> sexe >> numero >> heures >> salaire){
    Employe employe(sexe, numero, heures, salaire);

    // preparer un nouvel element
    Pointeur tempo = new Element;
    tempo->emp = employe;

    tempo->suivant = NULL;
    if (liste == NULL)
      liste = dernier = tempo;
    else {
      dernier->suivant = tempo ;
      dernier = tempo;
    }
	}

	aLire.close();   
}

void afficherDernier(Pointeur liste){
  while(liste->suivant)
    liste = liste->suivant;

  cout << liste->emp;
}

void chercher(Pointeur liste, const int numero, Pointeur & avant, Pointeur & cestLui){
  avant = NULL; // avant le 1er element : il n'en a pas => avant vaut NULL
  cestLui = liste; // cestLui pointe vers le 1er element
       
  while (cestLui && cestLui->emp.getNumero() != numero){
    // avant prendre la place de cestLui
    avant = cestLui;
                
    // cestLui s'avance
    cestLui = cestLui->suivant;                               
  }
}

void modifierSexe(Pointeur & liste, const int numero, const char sexe){
  // On declare les variables
  Pointeur avant, cestLui;

  chercher(liste, numero, avant, cestLui);

  cestLui->emp.setSexe(sexe);    
}

void modifierSal(Pointeur & liste, const int numero, const float salHebdo){
  // On declare les variables
  Pointeur avant, cestLui;

  chercher(liste, numero, avant, cestLui);

  cestLui->emp.setSalHebdo(salHebdo);
}

void supprimerPrem(Pointeur & liste){
  // On declare les variables
  Pointeur cestLui = liste;

  liste = liste->suivant;

  delete cestLui;
}

void supprimerDern(Pointeur & liste){
  // On declare les variables
  Pointeur avant, cestLui = liste;

  while(cestLui->suivant){
    // avant prendre la place de cestLui
    avant = cestLui;
                
    // cestLui s'avance
    cestLui = cestLui->suivant;    
  }

  avant->suivant = NULL;

  delete cestLui;
}

void supprimer(Pointeur & liste, const int numero){
  // On declare les variables
  Pointeur avant, cestLui;

  chercher(liste, numero, avant, cestLui);

  if (avant)
    avant->suivant = cestLui->suivant;                        
  else
    liste = liste->suivant;

  delete cestLui;
}

void compterSexe(Pointeur liste){
  // On declare les variables
  int nFemmes = 0, nHommes = 0;

  while(liste){
    if(liste->emp.getSexe() == 'F')
      nFemmes++;
    else
      nHommes++;
    liste = liste->suivant;
  }

  cout << "Il y a " << nFemmes << " femmes et " << nHommes << " hommes." 
       << endl;
}

float moyenneSalHebdo(Pointeur liste){
  // On declare des variables
  float salHebdoSomme = 0, salHebdoMoy;
  int nHommes = 0;

  while(liste){
    if(liste->emp.getSexe() == 'M'){
      salHebdoSomme += liste->emp.getSalHebdo();
      nHommes++;
    }

    liste = liste->suivant;
  }

  salHebdoMoy = salHebdoSomme / nHommes;

  return salHebdoMoy;
}

void maxSalHebdo(Pointeur liste){
  // On delcare des variables
  float maxSalHebdo = liste->emp.getSalHebdo();
  
  liste = liste->suivant;

  while(liste){
    if(liste->emp.getSexe() == 'F')
      maxSalHebdo = (maxSalHebdo > liste->emp.getSalHebdo()) ? maxSalHebdo : liste->emp.getSalHebdo();
      
    liste = liste->suivant;
  }

  cout << "Le salaire hebdomadaire le plus eleve chez les femmes est de " 
       << maxSalHebdo << endl;
}

void afficher(Pointeur liste){
  // On declare les variables
  int n = 0;

  while(liste){
    n++;
    // Test si 5 premiers
    if(n <= 5)
      cout << liste->emp;
    
    // Test si dernier
    if(! liste->suivant)
      cout << liste->emp;

    liste = liste->suivant;
  }
}
  
int main() {
  // On declare des variables
  float salHebdoMoy;
  Pointeur liste, dernier;
 
  lireRemplir("emp_h20.txt", liste, dernier);

  cout << liste->emp;
  afficherDernier(liste);
  cout << endl;

  modifierSexe(liste, 542, 'F');

  modifierSal(liste, 270, 1234.5);

  supprimerPrem(liste);
  supprimerDern(liste);
  supprimer(liste, 775);

  compterSexe(liste);
  cout << endl;

  salHebdoMoy = moyenneSalHebdo(liste);

  maxSalHebdo(liste);
  cout << endl;

  afficher(liste);
  cout << endl;

  return 0;
}