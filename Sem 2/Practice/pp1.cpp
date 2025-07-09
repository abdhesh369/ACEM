#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string ID, name, address, parentName, className;
    unsigned long long phone;
};

struct Marksheet {
    string ID, subject[6];
    int theoryMax[6], practicalMax[6];
    int theoryMarks[6], practicalMarks[6];
};

Student stu;
Marksheet mark;

void addStudent() {
    ofstream file("record.txt", ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "\n--- Add Student Record ---\n";
    cout << "ID: "; cin >> stu.ID;
    cin.ignore();
    cout << "Name: "; getline(cin, stu.name);
    cout << "Address: "; getline(cin, stu.address);
    cout << "Parent Name: "; getline(cin, stu.parentName);
    cout << "Class: "; getline(cin, stu.className);
    cout << "Phone: "; cin >> stu.phone;

    file.write((char*)&stu, sizeof(Student));
    file.close();
    cout << "Student added successfully!\n";
}

void searchStudent() {
    ifstream file("record.txt", ios::binary);
    string id;
    bool found = false;

    cout << "\n--- Search Student ---\n";
    cout << "Enter ID: ";
    cin >> id;

    while (file.read((char*)&stu, sizeof(Student))) {
        if (stu.ID == id) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n--- Student Found ---\n";
        cout << "ID: " << stu.ID << "\n";
        cout << "Name: " << stu.name << "\n";
        cout << "Address: " << stu.address << "\n";
        cout << "Parent: " << stu.parentName << "\n";
        cout << "Class: " << stu.className << "\n";
        cout << "Phone: " << stu.phone << "\n";
    } else {
        cout << "Student not found.\n";
    }

    file.close();
}

void modifyStudent() {
    fstream file("record.txt", ios::binary | ios::in | ios::out);
    string id;
    bool found = false;

    cout << "\n--- Modify Student ---\n";
    cout << "Enter ID to modify: ";
    cin >> id;

    while (file.read((char*)&stu, sizeof(Student))) {
        if (stu.ID == id) {
            cout << "Enter new details:\n";
            cout << "New ID: "; cin >> stu.ID;
            cin.ignore();
            cout << "New Name: "; getline(cin, stu.name);
            cout << "New Address: "; getline(cin, stu.address);
            cout << "New Parent Name: "; getline(cin, stu.parentName);
            cout << "New Class: "; getline(cin, stu.className);
            cout << "New Phone: "; cin >> stu.phone;

            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
            file.write((char*)&stu, sizeof(Student));
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Student modified successfully.\n";
    else
        cout << "Student not found.\n";
}

void deleteStudent() {
    ifstream in("record.txt", ios::binary);
    ofstream out("temp.txt", ios::binary);
    string id;
    bool deleted = false;

    cout << "\n--- Delete Student ---\n";
    cout << "Enter ID to delete: ";
    cin >> id;

    while (in.read((char*)&stu, sizeof(Student))) {
        if (stu.ID != id)
            out.write((char*)&stu, sizeof(Student));
        else
            deleted = true;
    }

    in.close(); out.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");

    if (deleted)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

void addMarksheet() {
    ofstream file("marksheet.txt", ios::binary | ios::app);
    cout << "\n--- Add Marksheet ---\n";
    cout << "Enter Student ID: ";
    cin >> mark.ID;

    for (int i = 0; i < 6; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> mark.subject[i];
        cout << "Theory Max, Practical Max: ";
        cin >> mark.theoryMax[i] >> mark.practicalMax[i];
        cout << "Theory Marks, Practical Marks: ";
        cin >> mark.theoryMarks[i] >> mark.practicalMarks[i];
    }

    file.write((char*)&mark, sizeof(Marksheet));
    file.close();
    cout << "Marksheet added successfully!\n";
}

void searchMarksheet() {
    ifstream file("marksheet.txt", ios::binary);
    string id;
    bool found = false;

    cout << "\n--- Search Marksheet ---\n";
    cout << "Enter Student ID: ";
    cin >> id;

    while (file.read((char*)&mark, sizeof(Marksheet))) {
        if (mark.ID == id) {
            found = true;
            break;
        }
    }

    if (found) {
        int total = 0, obtained = 0;
        cout << "\nMarksheet for ID: " << mark.ID << "\n";
        for (int i = 0; i < 6; i++) {
            cout << mark.subject[i] << ": "
                 << mark.theoryMarks[i] << "/" << mark.theoryMax[i]
                 << " T, " << mark.practicalMarks[i] << "/" << mark.practicalMax[i] << " P\n";
            total += mark.theoryMax[i] + mark.practicalMax[i];
            obtained += mark.theoryMarks[i] + mark.practicalMarks[i];
        }
        double percent = total ? (obtained * 100.0 / total) : 0;
        cout << "Total: " << obtained << "/" << total << "\n";
        cout << "Percentage: " << percent << "%\n";
    } else {
        cout << "Marksheet not found.\n";
    }

    file.close();
}

void menu() {
    int choice;
    while (true) {
        cout << "\n--- Student Record Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Modify Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Add Marksheet\n";
        cout << "6. Search Marksheet\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: modifyStudent(); break;
            case 4: deleteStudent(); break;
            case 5: addMarksheet(); break;
            case 6: searchMarksheet(); break;
            case 7: exit(0);
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
