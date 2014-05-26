/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:40
 */

#include "mylist.h"
#include <ctime>
#include <cstdlib>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;

/*
 * 
 */
int main() {
    try {
        myList<int> mylist;
        int input = 0;
        bool exit(false);
        std::srand(std::time(0));
        while (!exit) {
            cout << endl << " 1: Zufallszahl am Listenanfang hinzufuegen" << endl;
            cout << endl << " 2: Zufallszahl am Listenende hinzufuegen" << endl;
            cout << endl << " 3: Zufallszahl vom Listenanfang loeschen" << endl;
            cout << endl << " 4: Zufallszahl vom Listenende loeschen" << endl;
            cout << endl << " 5: Zufallszahl irgendwo in Liste einfuegen" << endl;
            cout << endl << " 6: Zufallszahl irgendwo in Liste loeschen" << endl;
            cout << endl << " 7: Liste ausgeben" << endl;
            cout << endl << " 0: Programm beenden" << endl;
            cin >> input;
            if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
            switch (input) {
                case 7:
                    mylist.print();
                    break;
                case 6:
                    mylist.print();
                    cout << "An welcher Stelle wollen Sie eine Zufallszahl loeschen?";
                    cin >> input;
                    if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
                    mylist.del(input);
                    break;
                case 5:
                    mylist.print();
                    cout << "An welcher Stelle wollen Sie eine Zufallszahl einfuegen? ";
                    cin >> input;
                    if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
                    mylist.ins(input, std::rand() % 1000);
                    break;
                case 4:
                    cout << "Geloeschter Wert war: " << mylist.pop_back() << endl;
                    break;
                case 3:
                    cout << "Geloeschter Wert war: " << mylist.pop_front() << endl;
                    break;
                case 2:
                    mylist.push_back(std::rand() % 1000);
                    break;
                case 1:
                    mylist.push_front(std::rand() % 1000);
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    throw std::runtime_error("Inkorrekte Eingabe!");
                    break;
            }
            cout << endl;
        }


        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}
