#include <iostream>

using namespace std;

struct Element
{ 
  char sexe;
  Element * suivant;
  float poids;
  float taille;
};

typedef Element * Pointeur ;

// creer en ordre LIFO
void creer(Pointeur & liste, int nombre){
  liste = NULL ;
  for(int i = 0; i < nombre; i++){
    Pointeur tempo = new Element;
    if(i % 2 == 0)
      tempo->sexe = 'F';
    else
      tempo->sexe = 'M';    
    tempo->suivant = liste ;
    liste = tempo; 
  }
}

int compter(Pointeur liste, const char sexe, const char message[]){
  // On initialise les variables
  int nOcc = 0;

  while(liste){
    if(liste->sexe == sexe){
      nOcc++;
    }
    liste = liste->suivant;
  }

  cout << "Il y a " << nOcc << message << endl;

  return nOcc;
}

void vcompter(Element & liste){
  // On initialise les variables
  int nFemmes = 0,
      nHommes = 0;

  while(true){
    if(liste.sexe == 'F')
      nFemmes++;
    else
      nHommes++;
    if(liste.suivant)
      liste = *liste.suivant;
    else
      break;
  }

  cout << "Il y a " << nFemmes << " femmes et " << nHommes << " hommes." 
       << endl;
}

float min(Pointeur liste, const char sexe, const char param, const char message[]){
  // La fonction retourne un parametre minimum d'un sexe donne.
  // On declare les variables
  float min;

  while(liste){
    if(liste->sexe == sexe)
      if(param == 'P')
        min = (min < liste->poids) ? min : liste->poids;
      else if(liste->sexe == 'T')
        min = (min < liste->taille) ? min : liste->taille;
    liste = liste->suivant;
  }

  cout << message << " est de " << min << endl;
}
              
int main(){
	// On declare les variables
  Pointeur liste;
  int nFemmes, nHommes;
  float poidsFMin, tailleMMin;

  creer(liste, 5);

  nFemmes = compter(liste, 'F', " femmes.");
  nHommes = compter(liste, 'M', " hommes.");
  cout << endl;

  vcompter(*liste);  
  
  poidsFMin = min(liste, 'F', 'P', "Le poids minimal chez les femmes");
  tailleMMin = min(liste, 'M', 'T', "La taille minimale chez les hommes");
  
  return 0;
}