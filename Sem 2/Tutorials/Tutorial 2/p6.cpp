// Develop a program using a class to with 3x3 matrix as a data menber.Overload the *operators so as to multiply two matrices.
#include <iostream>
using namespace std;
class matrix
{
private:
    int 
    mat[3][3];

public:
    void getdata()
    {
        cout << "Enter the elements of matrix" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> 
                mat[i][j];
            }
        }
    }
    matrix operator*(const matrix &m) {
        matrix temp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp.mat[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    temp.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return temp;
    }
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout <<
                mat[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main() {
    matrix m1, m2, m3;

    cout << "Enter first matrix:\n";
    m1.getdata();

    cout << "Enter second matrix:\n";
    m2.getdata();

    m3 = m1 * m2;

    m3.display();

    return 0;
}