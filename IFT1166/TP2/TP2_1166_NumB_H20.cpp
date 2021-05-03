// author: Nicolas Levasseur
#include <iostream>
#include <iomanip>
using namespace std;

void afficheTel(const string tel, const char message[]){
    /* Cette fonction sert a montrer un numero de telephone a
    l'utilisateur de maniere lisible.
    */
    cout << "Le telephone de " << message << " : (" << tel.substr(0, 3) 
         << ") " << tel.substr(3, 3) << "-" << tel.substr(6, 4) << endl;
}

void nbOccurences(const string str, const char chiffre, const char message[]){
    /* Cette fonction sert a trouver le nombre d'occurence d'un certain
    caractere (un chiffre) dans un string defini.
    */
    // On intialise notre compteur d'occurences
    int n = 0;

    // On teste si chaque caractere du string est celui qu'on recherche
    for(int i = 0; i < str.length(); i++)
        if(str[i] == chiffre)
            n++;
    
    // On montre le résultat à l'utilisateur
    cout << "Il y a " << n << " fois le chiffre " << chiffre << " dans " 
         << message << endl;
}

bool caractereCompris(const string str1, const string str2){
    /* Cette fonction regarde si tous les caracteres de str1 peuvent 
    etre obtenu dans str2.
    */
    // On intialise les variables et les compteurs
    int i = 0,
        j = 0,
        longueurStr1 = str1.length(),
        longueurStr2 = str2.length();
    bool resultatTest = true;

    // On effectue une boucle sur chaque element de str1 qu'on compare avec
    // chaque element de str2 jusqu'a ce qu'on trouve deux caracteres pareils
    while(j < longueurStr2){
        if(str1[i] == str2[j]){
            i++;
            j = -1;
        } // end if
        j++;
        if(i == longueurStr1)
            break;
    } // end while

    // Si la boucle est arrivee a j==longueurStr2, alors on sait qu'aucun
    // caractere ne se retrouve dans str2
    if(j == longueurStr2)
        resultatTest = false;
    
    return resultatTest;
}

void trouveCaracterePasLa(const string str1, const string str2, 
const char message[]){
    /* Cette fonction trouve les caracteres de str1 qui ne sont pas
    present dans str2.
    */
    // On initialise les variables
    int i = 0,
        j = 0,
        longueurStr1 = str1.length(),
        longueurStr2 = str2.length();
    bool dejaLa = false;
    string caracterePasLa = "";

    while(j <= longueurStr2){
        if(str1[i] == str2[j]){
            i++;
            j = -1;
        } // end if(str1[i] =str2[k])
        j++;

        if(i == longueurStr1)
            break;

        // Si la boucle est arrivee a j==longueurStr2, alors on sait que ce
        // caractere ne se retrouve pas dans str2 et on l'ajoute donc dans le
        // string prevu pour les caracteres absent, sauf s'il est deja dans
        // celui-ci
        if(j == longueurStr2){
            if(caracterePasLa.length() != 0)
                for(int k = 0; k < caracterePasLa.length(); k++)
                    if(str1[i] == caracterePasLa[k])
                        dejaLa = true;
            if(dejaLa == false){
                caracterePasLa.append(str1, i, 1);
                caracterePasLa.append(" ");
                i++;
                j = 0;
            } // end if(dejaLa == false)
        } // end if(j == longueurStr2)
    } // end while(j)

    cout << message << caracterePasLa << endl;
}

void afficheDivisible(const string nombre, const int diviseur, const int 
reste, const char message[]){
    /* Cette fonction trouve les chiffres d'un nombre qui sont divisible
    par un certain diviseur avec un certain reste, puis les mets en 
    ordre croissant.
    */
    // On initialise les variables
    char temp;
    string divisable = "";


    // On fait le test quels chiffres sont divisibles avec le reste voulu
    for(int i = 0; i < nombre.length(); i++)
        if((nombre[i] - '0') % diviseur == reste)
            divisable.append(nombre, i, 1);

    // On organise les chiffres en ordre croissant
    for(int i = 0; i < divisable.length() - 1; i++){   
        for(int j = i + 1; j < divisable.length(); j++){
            if((divisable[j] - '0') < (divisable[i] - '0')){
                temp = divisable[j];
                divisable[j] = divisable[i];
                divisable[i] = temp;
            } // end if
        } // end for(j)
    } // end for(i)

    // On enleve les doublets
    temp = divisable[0];
    for(int i = 1; i < divisable.length(); i++){
        if(divisable[i] == temp){
            divisable.erase(i, 1);
            i -= 1;
        } // end if
        else{
            temp = divisable[i];
            divisable.insert(i, " ");
            i++;
        } // end else
    } // end for(i)

    cout << message << divisable << endl;
}

void afficherMax(const string nombre, const char message[]){
    /* Cette fonction trouve le chiffre le plus grand dans chaque nombre et
    le montre a l'utilisateur.
    */
    // On declare les variables
    int max = nombre[0] - '0';

    // On trouve le chiffre maximum
    for(int i = 1; i < nombre.length(); i++)
        if(max < nombre[i] - '0')
            max = nombre[i] - '0';

    // On affiche le resultat
    cout << "le plus grand chiffre de " << message << " : " << max << endl;
}

int main(){
    // On declare les numeros de telephone
    const string telUdM = ("5143436111"),
                 telJean = ("4501234567");
    bool resultatTest;

    // On affiche les differents numeros de telephone
    afficheTel(telUdM, "l'Universite de Montreal");
    afficheTel(telJean, "Jean");
    cout << endl;

    // On affiche le nombre d'occurences de certains chiffres dans les numeros
    nbOccurences(telUdM, '3', "le numero de telephone de l'UdeM");
    nbOccurences(telUdM, '1', "le numero de telephone de l'UdeM");
    nbOccurences(telJean, '4', "le numero de telephone de Jean");
    cout << endl;

    // On test si les chiffres du numero de l'UdeM se retrouvent tous dans le 
    // numero de Jean et on montre le resultat a l'utilisateur
    resultatTest = caractereCompris(telUdM, telJean);
    cout << "Resultat du test de caracteres qui stipule que les chiffres du "
         << "numero de telephone de l'Universite de Montreal sont compris "
         << "dans ceux du numero de telephone de Jean : " << resultatTest 
         << endl << endl;

    // On affiche les chiffres du numero de telephone de Jean qui ne se 
    // retrouvent pas dans le numero de l'UdeM
    trouveCaracterePasLa(telJean, telUdM, "Voici les chiffres du numero de "
    "telephone de Jean qui ne figurent pas dans le numero de telephone de "
    "UDM : ");
    cout << endl;

    // On affiche les chiffres du numero de telephone de Jean qui sont pairs
    afficheDivisible(telJean, 2, 0, "Les chiffres pairs de telephone de "
    "Jean : ");
    cout << endl;

    // On affiche les chiffres du numero de telephone de l'UdeM impairs
    afficheDivisible(telUdM, 2, 1, "Les chiffres impairs de telephone "
    "d'UdeM : ");
    cout << endl;

    // On affiche les chiffres maximums de chaque numerp de telephone
    afficherMax(telUdM, "tel UdeM");
    afficherMax(telJean, "telephone de Jean");
    cout << endl;

    return 0;
}
