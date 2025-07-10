// Hangman Game
// The hangman project game consists of guessing a secret word of a given length by entering one letter at a time. The game ends if the user does not correctly guess the word within the allotted number of guesses. The Hangman game will utilize classes to store the hidden word and guesses a class containing member methods used to track progress, and a class to represent the hangman figure. The game logic will be written using a variety of features such as structs, switch statements, and loops of C++ programming language.

// Technologies Required: C++ programming language, Object Oriented Programming (OOPS).
#include <iostream>
using namespace std;

class lengthfeet {
    float feet;

public:
    lengthfeet() {
        feet = 0;
    }

    lengthfeet(float x) {
        feet = x;
    }

    void displayf() {
        cout << "Length in feet: " << feet << endl;
    }
};

class lengthmeter : public lengthfeet {
    float meter;

public:
    lengthmeter() {
        meter = 0;
    }

    lengthmeter(float y) {
        meter = y;
    }

    operator lengthfeet() {
        return lengthfeet(meter * 3.28084);  
    }
    void displaym() {
        cout << "Length in feet: " << meter << endl;
    }
};

int main() {
    lengthmeter m(110);        
    lengthfeet f;

    f = m;                    
    f.displayf();              
    // m.displaym();              
    return 0;
}



// #include<iostream>
// using namespace std;

// class LengthFeet{
	
// 	float value;
	
// 	public: 
	
// 		LengthFeet(float f= 0){
// 			value = f;
// 		}
		
// 		displayFeet(){
// 			cout<<"Feet is : "<<value;
// 		}
	
// };

// class LengthMeters{
	
// 	float value;
	
// 	public:
	
// 		LengthMeters(float f= 0) {
			
// 			value = f;
// 		}
		
// 		displayMeters(){
// 			cout<<"Meters is : "<<value;
// 		}
		
		
// 		operator LengthFeet(){
			
// 			return LengthFeet(value*3.28);
// 		}
	
// };



// int main(){
	
// 	LengthMeters lm(5.0);
	
// 	LengthFeet lf = lm;
	
// 	lf.displayFeet();
// }

