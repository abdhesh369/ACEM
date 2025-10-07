// Write a function to pass two objects of type LandMeasure and return their sum
//(16 Ana = 1 Ropani, 4 Paisa= 1 Ana, 4 Dam= 1 Paisa)
#include <iostream>
using namespace std;
class LandMeasure
{
public:
    int ana, ropani, paisa, dam;

    LandMeasure(int r = 0, int a = 0, int p = 0, int d = 0)
    {
        ropani = r;
        ana = a;
        paisa = p;
        dam = d;
    }
    void display()
    {
        cout << "ropani= " << ropani << endl
             << "ana= " << ana << endl
             << "paisa= " << paisa << endl
             << "dam= " << dam << endl;
    }
    LandMeasure addLand(const LandMeasure &other)
    {
        LandMeasure sum;
        sum.dam = dam + other.dam;
        sum.paisa = paisa + other.paisa;
        sum.ana = ana + other.ana;
        sum.ropani = ropani + other.ropani;

        if (sum.dam >= 4)
        {
            sum.paisa += sum.dam / 4;
            sum.dam = sum.dam % 4;
        }

        if (sum.paisa >= 4)
        {
            sum.ana += sum.paisa / 4;
            sum.paisa = sum.paisa % 4;
        }

        if (sum.ana >= 16)
        {
            sum.ropani += sum.ana / 16;
            sum.ana = sum.ana % 16;
        }

        return sum;
    }
};

int main()
{
    LandMeasure l1(2, 4, 5, 5), l2(4, 5, 7, 8);
    LandMeasure total = l1.addLand(l2);
    l1.display();
    l2.display();
    cout << "Sum:" << endl;
    total.display();
    return 0;
}