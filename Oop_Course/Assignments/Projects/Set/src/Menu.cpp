#include "../include/Menu.h"

void Menu::run() {
    int n;
    
    do {
        menuWrite();
        std::cout << std::endl << "<<<<<";
        std::cin >> n;
        switch(n) {
            case 1:
            insert(); 
            break;
            case 2: 
            removeElement();
            break;
            case 3: 
            removeIndex();
            break;
            case 4: 
            print();
            break;
            case 5: 
            member();
            break;
            case 6: 
            empty();
            break;
            case 7: 
            sum();
            break;
            case 8: 
            random();
            break;
        }
    } while(n!=0);
}

void Menu::menuWrite() {
    using std::cout;
    using std::endl;
    cout << endl;
    cout << "0.- Quit" << endl;
    cout << "1.- Insert an element" << endl;
    cout << "2.- Remove an element" << endl;
    cout << "3.- Remove an element by index" << endl;
    cout << "4.- Print a set" << endl;
    cout << "5.- Check if set has a specific element" << endl;
    cout << "6.- Check if the set is empty" << endl;
    cout << "7.- Get the sum the elements in the set" << endl;
    cout << "8.- Get the random element from the set" << endl;   
}

void Menu::insert() {
    int elem;
    std::cout << "Element: ";
    std::cin >> elem;
    a.insert(elem);
}

void Menu::print() {
    try {
        a.print();
    } catch(Set::Exception e) {
        if(e == Set::EMPTYSET)
            std::cout << "Nothing to print. The set is empty!" << std::endl;
    }
    
}

void Menu::removeElement() {
    std::cout << "Element: ";
    int elem;
    std::cin >> elem;
    try {
        a.remove_by_element(elem);
    } catch(Set::Exception e) {
        if(e == Set::MISSING_KEY)
            std::cout << "There is no such element in the set!" << std::endl;
    }
}

void Menu::removeIndex() {
    std::cout << "Index: ";
    int ind;
    std::cin >> ind;
    try {
        a.remove_by_index(ind);
    } catch(Set::Exception e) {
        if(e == Set::OUT_OF_SIZE)
            std::cout << "Out of the size! Please, enter the valid index." << std::endl;
    }
}

void Menu::member() {
    std::cout << "Element: ";
    int elem;
    std::cin >> elem;
    if(a.isMember(elem)) {
        std::cout << "Success! There is such element in the set" << std::endl;
    } else { 
        std::cout << "There is not such element in the set!" << std::endl;
    }
}

void Menu::empty() {
    std::cout << "The set is " << (a.isEmpty() ? "" : "not") << " empty!" << std::endl;
}

void Menu::sum() {
    std::cout << "The sum of the elements in the set is: " << a.getSum() << std::endl;
}

void Menu::random() {
    try {
        std::cout << a.random() << std::endl;
    } catch(Set::Exception e) {
        if(e == Set::EMPTYSET)
            std::cout << "Nothing to print. The set is empty!" << std::endl;
    }
}