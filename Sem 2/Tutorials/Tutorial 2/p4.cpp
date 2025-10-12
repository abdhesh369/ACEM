// Write a program to overload + operator to concatenate two strings.
#include <iostream>
using namespace std;
class sentance
{
    string word;

public:
    sentance(string s = "")
    {
        word = s;
    }
    sentance operator+(const sentance &d)
    {
        sentance temp;
        temp.word = word + d.word;
        return temp;
    }
    void display()
    {
        cout << "Concatenated String: " << word << endl;
    }
};
int main()
{
    sentance s1("Abdhesh ");
    sentance s2("sah ");
    sentance s3;
    s3 = s1 + s2;
    s3.display();

    return 0;
}