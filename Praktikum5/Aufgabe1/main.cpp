/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matrnr.: 736476
 *
 * Created on 6. Juni 2014, 14:53
 */

#include "tree.h"
#include "time.h"
#include <string>
#include <cstdlib>

using std::cerr;
using std::cin;

template<typename T>
void test(T result, T expected, std::string message) {
    std::cout << message << ": ";
    if (result != expected)
        std::cout << "failed [" << result << "]" << std::endl;
    else
        std::cout << "succeeded" << std::endl;
}


void random_tree(binTree<char>& target, unsigned int count = 10) {
    for(unsigned int i = 0; i < count; ++i)
    {
        target.insert((std::rand()% 26) +65 );
    }
}

void run_tests()
{
        binTree<char> baum;

        test<int>(baum.size(), 0, "Groesse leerer Baum = 0");
        test<int>(baum.height(), -1, "Hoehe leerer Baum = -1");
        baum.insert('s');
        test<int>(baum.size(), 1, "Groesse Baum nur Wurzel = 1");
        test<int>(baum.height(), 0, "Hoehe Baum nur Wurzel = 0");
        baum.insert('o');
        test<int>(baum.size(), 2, "Groesse Baum = 2");
        test<int>(baum.height(), 1, "Hoehe Baum = 1");
        baum.insert('r');
        test<int>(baum.size(), 3, "Groesse Baum = 3");
        test<int>(baum.height(), 2, "Hoehe Baum = 2");
        baum.insert('t');
        test<int>(baum.size(), 4, "Groesse Baum = 4");
        test<int>(baum.height(), 2, "Hoehe Baum = 2");

        test<bool>(baum.find('r') != 0, true, "Suche r erfolgreich");
        test<bool>(baum.find('k') != 0, false, "Suche k nicht erfolgreich");
        
        test<std::string>(baum.inOrder(), "o r s t ", "InOrder = o r s t"); //In-Order Traversierung
        test<std::string>(baum.levelOrder(), "s o t r ", "LevelOrder = s o t r"); 
        
        test<bool>(baum.empty(), false, "Nichtleerer Baum: empty = false");
        baum.clear();
        test<bool>(baum.empty(), true, "Leerer Baum: empty = true");
        
        baum.insert_top('b');
        baum.insert_top('c');
        baum.insert_top('a');
        baum.insert_top('d');
        
        test<int>(baum.size(), 4, "Groesse Baum = 4");
        test<int>(baum.height(), 3, "Hoehe Baum = 3");
        
        
        test<std::string>(baum.inOrder(), "a b c d ", "InOrder = a b c d"); //In-Order Traversierung
        test<std::string>(baum.levelOrder(), "d a c b ", "LevelOrder = d a c b");
        
        binTree<char> copy(baum);
        test<std::string>(copy.inOrder(), baum.inOrder(), "InOrder Kopie = InOrder Baum");
        test<std::string>(copy.levelOrder(), baum.levelOrder(), "LevelOrder Kopie = LevelOrder Baum");
        test<int>(copy.size(), baum.size(), "Groesse Kopie = Groesse Baum");
        test<int>(copy.height(), baum.height(), "Hoehe Kopie = Hoehe Baum");
}

void menuCreateRandom(binTree<char>& baum)
{
    cout << "Anzahl Zufallselemente: ";
    int in = 0;
    cin >> in;
    if(!cin)
        throw std::runtime_error("Ungueltige Eingabe");
    random_tree(baum, in);
    cout << "InOrder: " << baum.inOrder() <<
            ", LevelOrder: " << baum.levelOrder() << endl;
}

void menuInsert(binTree<char>& baum)
{
    cout << "Wert: ";
    char in = 0;
    cin >> in;
    if(!cin)
        throw std::runtime_error("Ungueltige Eingabe");
    baum.insert(in);
    cout << "InOrder: " << baum.inOrder() <<
            ", LevelOrder: " << baum.levelOrder() << endl;   
}

void menuInsertTop(binTree<char>& baum)
{
    cout << "Wert: ";
    char in = 0;
    cin >> in;
    if(!cin)
        throw std::runtime_error("Ungueltige Eingabe");
    baum.insert_top(in);
    cout << "InOrder: " << baum.inOrder() <<
            ", LevelOrder: " << baum.levelOrder() << endl;   
}

int main() {
    try {
        std::srand(time(0));
        cout << "PAD BinTree" << endl
                << "1: Tests ausfuehren" << endl
                << "2: Zufallsbaum erstellen" << endl
                << "3: insert" << endl
                << "4: insert_top"<<endl
                << "5: clear"<<endl
                << "0: Beenden"<<endl;
        binTree<char> baum;
        while(true)
        {
            cout << "Option[1-5]: ";
            int option = 0;
            cin >> option;
            if(!cin)
                throw std::runtime_error("Ungueltige Eingabe");
            switch(option)
            {
                case 1:
                    run_tests();
                    break;
                case 2:
                    menuCreateRandom(baum);
                    break;
                case 3:
                    menuInsert(baum);
                    break;
                case 4:
                    menuInsertTop(baum);
                    break;
                case 5:
                {
                    baum.clear();
                    cout << "Baum geleert" << endl;
                    break;
                }
                case 0:
                    return 0;
            }
        }
    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}
