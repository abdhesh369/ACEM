#include <iostream>
using namespace std;

int main() {
    try {
        int choice;
        cout << "Enter 1 or 2: ";
        cin >> choice;
        if(choice == 1) throw 100;            
        else if(choice == 2) throw "Oops!";   
        else throw 3.14;                        
    }
    catch(int e) {
        cout << "Caught int: " << e << endl;
    }
    catch(const char* e) {
        cout << "Caught string: " << e << endl;
    }
    catch(...) {
        cout << "Caught something else!" << endl;
    }
    return 0;
}
