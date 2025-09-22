#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    bool note;
    int asd1;
    int asd2;
};

bool isFileEmpty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

int getLastId(const string& filename) {
    ifstream file(filename);
    if (!file.is_open() || isFileEmpty(filename)) return 0;
    Student s; int lastId = 0;
    while (file >> s.id >> s.name >> s.age >> s.note >> s.asd1 >> s.asd2)
        lastId = s.id;
    return lastId;
}

void addStudent(const string& filename) {
    Student s;
    s.id = getLastId(filename) + 1;
    cout << "\nNom: "; cin >> s.name;
    cout << "Age: "; cin >> s.age;
    s.note = false; s.asd1 = 0; s.asd2 = 0;
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << s.id << " " << s.name << " " << s.age 
             << " " << s.note << " " << s.asd1 << " " << s.asd2 << endl;
        cout << "Etudiant ajoute avec ID " << s.id << "\n";
    }
}

void showAll(const string& filename) {
    ifstream file(filename);
    if (!file.is_open() || isFileEmpty(filename)) {
        cout << "\nAucun etudiant trouve.\n"; return;
    }
    Student s;
    cout << "\nListe des etudiants:\n";
    while (file >> s.id >> s.name >> s.age >> s.note >> s.asd1 >> s.asd2) {
        cout << "ID:" << s.id << " | Nom:" << s.name << " | Age:" << s.age;
        if (s.note) cout << " | Notes:" << s.asd1 << "," << s.asd2;
        cout << endl;
    }
}

void searchStudent(const string& filename) {
    string name; cout << "\nNom de l'etudiant: "; cin >> name;
    ifstream file(filename);
    if (!file.is_open() || isFileEmpty(filename)) {
        cout << "Aucun etudiant trouve.\n"; return;
    }
    Student s; bool found=false;
    while (file >> s.id >> s.name >> s.age >> s.note >> s.asd1 >> s.asd2) {
        if (s.name == name) {
            cout << "Trouve: ID:" << s.id << " | Age:" << s.age << endl;
            found = true;
        }
    }
    if (!found) cout << "Aucun etudiant avec ce nom.\n";
}

void deleteStudent(const string& filename) {
    int id; cout << "\nID de l'etudiant a supprimer: "; cin >> id;
    ifstream file(filename); ofstream temp("temp.txt");
    if (!file.is_open()) { cout << "Pas de fichier.\n"; return; }
    Student s; bool deleted=false;
    while (file >> s.id >> s.name >> s.age >> s.note >> s.asd1 >> s.asd2) {
        if (s.id == id) { deleted=true; continue; }
        temp << s.id << " " << s.name << " " << s.age 
             << " " << s.note << " " << s.asd1 << " " << s.asd2 << endl;
    }
    file.close(); temp.close();
    remove(filename.c_str()); rename("temp.txt", filename.c_str());
    cout << (deleted ? "Etudiant supprime.\n" : "Etudiant introuvable.\n");
}

void updateNote(const string& filename) {
    int id; cout << "\nID de l'etudiant: "; cin >> id;
    ifstream file(filename); ofstream temp("temp.txt");
    if (!file.is_open() || isFileEmpty(filename)) {
        cout << "Aucun etudiant trouve.\n"; return;
    }
    Student s; bool updated=false;
    while (file >> s.id >> s.name >> s.age >> s.note >> s.asd1 >> s.asd2) {
        if (s.id == id) {
            cout << "Note 1: "; cin >> s.asd1;
            cout << "Note 2: "; cin >> s.asd2;
            s.note = true; updated=true;
        }
        temp << s.id << " " << s.name << " " << s.age 
             << " " << s.note << " " << s.asd1 << " " << s.asd2 << endl;
    }
    file.close(); temp.close();
    remove(filename.c_str()); rename("temp.txt", filename.c_str());
    cout << (updated ? "Notes mises a jour.\n" : "Etudiant introuvable.\n");
}

void menu(const string& filename) {
    int choice;
    do {
        cout << "\n===== Gestion des Etudiants =====\n"
             << "1. Ajouter un etudiant\n"
             << "2. Afficher tous\n"
             << "3. Rechercher\n"
             << "4. Supprimer\n"
             << "5. Mettre a jour les notes\n"
             << "0. Quitter\n"
             << "Choix: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(filename); break;
            case 2: showAll(filename); break;
            case 3: searchStudent(filename); break;
            case 4: deleteStudent(filename); break;
            case 5: updateNote(filename); break;
            case 0: cout << "Fin du programme.\n"; break;
            default: cout << "Choix invalide.\n"; break;
        }
    } while (choice != 0);
}

int main() {
    menu("students.txt");
    return 0;
}
