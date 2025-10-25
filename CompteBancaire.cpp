#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;

public:
   
    CompteBancaire() {
        titulaire = "Inconnu";
        solde = 0.0;
        cout << "[Création] Compte par défaut pour " << titulaire << " avec un solde de " << solde << " DH" << endl;
    }

  
    CompteBancaire(const string& nom, double montant) {
        titulaire = nom;
        solde = montant;
        cout << "[Création] Compte de " << titulaire << " avec un solde initial de " << solde << " DH" << endl;
    }

   
    CompteBancaire(const CompteBancaire& autre) {
        titulaire = autre.titulaire;
        solde = autre.solde;
        cout << "[Copie] Compte copié depuis " << autre.titulaire << endl;
    }

   
    void afficher() const {
        cout << "Titulaire : " << titulaire << ", Solde : " << solde << " DH" << endl;
    }

   
    ~CompteBancaire() {
        cout << "[Destruction] Compte de " << titulaire << " détruit." << endl;
    }
};

// --- Programme principal ---
int main() {
    CompteBancaire compte1;                           // constructeur par défaut
    CompteBancaire compte2("Alice", 1500.0);          // constructeur paramétré
    CompteBancaire compte3 = compte2;                 // constructeur de copie

    cout << "\n--- Affichage des comptes ---" << endl;
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << "\n--- Fin du programme ---" << endl;
    return 0; // les destructeurs sont appelés automatiquement ici
}
