// Full C++ version with college heading, border, and all features
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

void drawRectangle() {
    int i;
    gotoxy(0, 0); cout << (char)201;
    for (i = 1; i < 110; i++) { gotoxy(i, 0); cout << (char)205; }
    gotoxy(110, 0); cout << (char)187;
    for (i = 1; i < 25; i++) {
        gotoxy(110, i);
        if (i == 6) cout << (char)185;
        else cout << (char)186;
    }
    gotoxy(110, 25); cout << (char)188;
    for (i = 109; i > 0; i--) {
        gotoxy(i, 25);
        if (i == 35) cout << (char)202;
        else cout << (char)205;
    }
    gotoxy(0, 25); cout << (char)200;
    for (i = 24; i > 0; i--) {
        gotoxy(0, i);
        if (i == 6) cout << (char)204;
        else cout << (char)186;
    }
    for (i = 1; i < 110; i++) {
        gotoxy(i, 6);
        if (i == 35) cout << (char)203;
        else cout << (char)205;
    }
    for (i = 7; i < 25; i++) {
        gotoxy(35, i);
        cout << (char)186;
    }
}

void clearWindow() {
    for (int i = 37; i < 110; i++) {
        for (int j = 7; j < 25; j++) {
            gotoxy(i, j); cout << " ";
        }
    }
}

void window() {
    drawRectangle();
    gotoxy(28, 2); SetColor(50);
    cout << "STUDENT RECORD SYSTEM";
    gotoxy(20, 3); cout << "ADVANCED COLLAGE OF ENGINEERING AND MANAGEMENT";
    gotoxy(31, 4); cout << "Estd.: 2018 A.D.";
    gotoxy(25, 24); SetColor(12);
}

void print_heading(const string& title) {
    SetColor(31);
    gotoxy(45, 8);
    cout << "SRS : " << title;
    SetColor(17);
}

void add_student() {
    clearWindow();
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
    clearWindow();
    print_heading("Search Record");
    string id; bool found = false;
    gotoxy(37, 10); cout << "Enter ID to search: "; cin >> id;
    ifstream file("record.txt", ios::binary);
    while (file.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        if (stu.ID == id) { found = true; break; }
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

void modify_student() {
    clearWindow();
    print_heading("Modify Record");
    string id; bool found = false;
    gotoxy(37, 10); cout << "Enter ID to modify: "; cin >> id;
    fstream file("record.txt", ios::binary | ios::in | ios::out);
    while (file.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        streampos pos = file.tellg();
        if (stu.ID == id) {
            gotoxy(37, 12); cout << "New ID: "; cin >> stu.ID;
            gotoxy(37, 13); cout << "New Name: "; cin.ignore(); getline(cin, stu.name);
            gotoxy(37, 14); cout << "New Address: "; getline(cin, stu.add);
            gotoxy(37, 15); cout << "New Parent's Name: "; getline(cin, stu.parname);
            gotoxy(37, 16); cout << "New Class: "; getline(cin, stu.Class);
            gotoxy(37, 17); cout << "New Phone No: "; cin >> stu.phone_no;
            file.seekp(pos - static_cast<streampos>(sizeof(Student)));
            file.write(reinterpret_cast<char*>(&stu), sizeof(Student));
            found = true;
            break;
        }
    }
    file.close();
    if (!found) gotoxy(37, 19); cout << "Record not found.";
}

void delete_student() {
    clearWindow();
    print_heading("Delete Record");
    string id; gotoxy(37, 10); cout << "Enter ID to delete: "; cin >> id;
    ifstream file("record.txt", ios::binary);
    ofstream temp("temp.txt", ios::binary);
    bool deleted = false;
    while (file.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        if (stu.ID != id) temp.write(reinterpret_cast<char*>(&stu), sizeof(Student));
        else deleted = true;
    }
    file.close(); temp.close();
    remove("record.txt"); rename("temp.txt", "record.txt");
    gotoxy(37, 12);
    if (deleted) cout << "Record deleted successfully.";
    else cout << "Record not found.";
}

void marksheet() {
    clearWindow();
    print_heading("Add Marksheet");
    ofstream file("marksheet.txt", ios::binary | ios::app);
    gotoxy(37, 10); cout << "Enter Student ID: "; cin >> mark.ID;
    for (int i = 0; i < 6; i++) {
        gotoxy(37, 12 + i * 3); cout << "Subject " << (i + 1) << " name: "; cin >> mark.sub[i];
        gotoxy(37, 13 + i * 3); cout << "Theory max, Practical max: "; cin >> mark.tmt[i] >> mark.tmp[i];
        gotoxy(37, 14 + i * 3); cout << "Theory obtained, Practical obtained: "; cin >> mark.tm[i] >> mark.pm[i];
    }
    file.write(reinterpret_cast<char*>(&mark), sizeof(Marksheet));
    file.close();
    gotoxy(40, 22); cout << "Marksheet successfully added.";
}

void search_marksheet() {
    clearWindow();
    print_heading("Search Marksheet");
    string id; gotoxy(37, 10); cout << "Enter ID to search: "; cin >> id;
    ifstream file("marksheet.txt", ios::binary); bool found = false;
    while (file.read(reinterpret_cast<char*>(&mark), sizeof(Marksheet))) {
        if (mark.ID == id) { found = true; break; }
    }
    file.close();
    if (found) {
        gotoxy(37, 12); cout << "Marksheet Found for ID: " << mark.ID;
        int total = 0, obtained = 0;
        for (int i = 0; i < 6; i++) {
            gotoxy(37, 14 + i * 2);
            cout << mark.sub[i] << " T: " << mark.tmt[i] << "/" << mark.tm[i]
                 << " P: " << mark.tmp[i] << "/" << mark.pm[i];
            total += mark.tmt[i] + mark.tmp[i];
            obtained += mark.tm[i] + mark.pm[i];
        }
        gotoxy(37, 14 + 6 * 2); cout << "Total: " << obtained << "/" << total;
        double percentage = total ? (obtained * 100.0 / total) : 0;
        gotoxy(37, 15 + 6 * 2); cout << "Percentage: " << percentage << "%";
    } else {
        gotoxy(37, 12); cout << "Marksheet not found.";
    }
}

void main_menu() {
    int choice;
    while (true) {
        gotoxy(2, 8); cout << "1. Add Student";
        gotoxy(2, 9); cout << "2. Search Student";
        gotoxy(2, 10); cout << "3. Modify Student";
        gotoxy(2, 11); cout << "4. Delete Student";
        gotoxy(2, 12); cout << "5. Add Marksheet";
        gotoxy(2, 13); cout << "6. Search Marksheet";
        gotoxy(2, 14); cout << "7. Exit";
        gotoxy(2, 16); cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
            case 1: add_student(); break;
            case 2: search_student(); break;
            case 3: modify_student(); break;
            case 4: delete_student(); break;
            case 5: marksheet(); break;
            case 6: search_marksheet(); break;
            case 7: exit(0);
            default: gotoxy(2, 18); cout << "Invalid choice."; break;
        }
        getch();
    }
}

int main() {
    ClearConsoleToColors(17, 14);
    window();
    main_menu();
    return 0;
}
