// Write a C++ program that converts kilograms to grams using pass by reference.
// Create a namespace called WeightConversion.
// Inside it, define a function kgToGram() that takes kilograms as input (by reference) and stores the result in grams (also by reference).
// In main(), ask the user to enter a value in kilograms, then display the converted grams.
#include <iostream>
using namespace std;

namespace weightconversion
{
    void kgtogram(float &kg,float &gram)
    {
    gram = kg * 1000;
    }
};
int main()
{
    float kg,gram;
    cout<<"Enter the weight in kg: "<<endl;
    cin>>kg;
    weightconversion::kgtogram(kg,gram);
    cout<<"gram="<<gram;
return 0;
}
