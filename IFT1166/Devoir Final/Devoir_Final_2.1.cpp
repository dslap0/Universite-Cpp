#include <iostream>
#include <string>
using namespace std;

void compare(string str1, string str2){
    // On compare les elements du premier string a ceux du deuxieme
    // On declare des variables
    bool test = false;

    // On teste chaque char dans str1 sur chaque char dans str2
    for(int i = 0; i < str1.length(); i++){
        for(int j = 0; j < str2.length(); j++){
            if(str1[i] == str2[j]){
                test = true;
                break;
            }
        }
        if(! test)
            cout << str1[i];
        test = false;
    }

    // On finit la ligne
    cout << endl;
}

int main(){
    // On declare des variables
    string naissance1 =  "1992-07-15",
           naissance2 =  "1991-02-14";

    compare(naissance1, naissance2);
    compare(naissance2, naissance1);

    return 0;
}
