// Converted from C to C++
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Student {
    string ID;
    string name;
    string add;
    string parname;
    string Class;
    unsigned long long phone_no;
};

struct Marksheet {
    string sub[6], ID;
    int tmt[6], tmp[6], pm[6], tm[6];
};

Student stu;
Marksheet mark;

COORD coord = {0, 0};

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void ClearConsoleToColors(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleTextAttribute(hStdOut, wColor);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
}

void print_heading(const string& title) {
    SetColor(31);
    gotoxy(45, 8);
    cout << "SRS : " << title;
    SetColor(17);
}

void add_student() {
    system("cls");
    print_heading("Add Record");
    ofstream file("record.txt", ios::binary | ios::app);
    if (!file) {
        MessageBoxW(0, L"Error opening file", L"Warning", 0);
        return;
    }

    gotoxy(37, 10); cout << "ID: "; cin >> stu.ID;
    gotoxy(37, 12); cout << "Name: "; cin.ignore(); getline(cin, stu.name);
    gotoxy(37, 14); cout << "Address: "; getline(cin, stu.add);
    gotoxy(37, 16); cout << "Parent's Name: "; getline(cin, stu.parname);
    gotoxy(37, 18); cout << "Class: "; getline(cin, stu.Class);
    gotoxy(37, 20); cout << "Phone Number: "; cin >> stu.phone_no;

    file.write(reinterpret_cast<char*>(&stu), sizeof(Student));
    file.close();
    gotoxy(40, 22); cout << "Record successfully added.";
}

void search_student() {
    system("cls");
    print_heading("Search Record");
    string id;
    bool found = false;

    gotoxy(37, 10); cout << "Enter ID to search: "; cin >> id;
    ifstream file("record.txt", ios::binary);

    while (file.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        if (stu.ID == id) {
            found = true;
            break;
        }
    }
    if (found) {
        gotoxy(37, 12); cout << "Record Found";
        gotoxy(37, 14); cout << "ID: " << stu.ID;
        gotoxy(37, 15); cout << "Name: " << stu.name;
        gotoxy(37, 16); cout << "Address: " << stu.add;
        gotoxy(37, 17); cout << "Parent's Name: " << stu.parname;
        gotoxy(37, 18); cout << "Class: " << stu.Class;
        gotoxy(37, 19); cout << "Phone No: " << stu.phone_no;
    } else {
        gotoxy(37, 12); cout << "Record not found.";
    }
    file.close();
}

void marksheet() {
    system("cls");
    print_heading("Add Marksheet");
    ofstream file("marksheet.txt", ios::binary | ios::app);
    gotoxy(37, 10); cout << "Enter Student ID: "; cin >> mark.ID;
    for (int i = 0; i < 6; i++) {
        gotoxy(37, 12 + i * 2); cout << "Subject " << (i + 1) << " name: "; cin >> mark.sub[i];
        gotoxy(37, 13 + i * 2); cout << "Theory max, Practical max: "; cin >> mark.tmt[i] >> mark.tmp[i];
        gotoxy(37, 14 + i * 2); cout << "Theory obtained, Practical obtained: "; cin >> mark.tm[i] >> mark.pm[i];
    }
    file.write(reinterpret_cast<char*>(&mark), sizeof(Marksheet));
    file.close();
    gotoxy(40, 22); cout << "Marksheet successfully added.";
}

void main_menu() {
    int choice;
    while (true) {
        system("cls");
        SetColor(28);
        gotoxy(2, 8); cout << "1. Add Student";
        gotoxy(2, 10); cout << "2. Search Student";
        gotoxy(2, 12); cout << "3. Add Marksheet";
        gotoxy(2, 14); cout << "4. Exit";
        gotoxy(2, 16); cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: add_student(); break;
            case 2: search_student(); break;
            case 3: marksheet(); break;
            case 4: exit(0);
            default: gotoxy(2, 18); cout << "Invalid choice."; break;
        }
        _getch();
    }
}

int main() {
    ClearConsoleToColors(17, 14);
    main_menu();
    return 0;
}
