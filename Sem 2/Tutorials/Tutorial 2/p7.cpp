// Write a program to add two matrices by overloading the + operator.
#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int mat[10][10];

public:
    void getData()
    {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    void display()
    {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix m)
    {
        Matrix temp;
        if (rows != m.rows || cols != m.cols)
        {
            cout << "\nError: Matrices must have the same dimensions to add.\n";
            temp.rows = temp.cols = 0;
            return temp;
        }

        temp.rows = rows;
        temp.cols = cols;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }
};

int main()
{
    Matrix m1, m2, m3;

    cout << "Enter data for first matrix:\n";
    m1.getData();

    cout << "\nEnter data for second matrix:\n";
    m2.getData();

    m3 = m1 + m2;

    cout << "\nSum of matrices:\n";
    m3.display();

    return 0;
}
