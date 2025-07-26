#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student
{
    string ID, name, address, parentName, className;
    unsigned long long phone;
};

struct Marksheet
{
    string ID, subject[6];
    int theoryMax[6], practicalMax[6];
    int theoryMarks[6], practicalMarks[6];
};

void addStudent()
{
    ofstream file("record.txt", ios::app);
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    Student stu;
    cout << "\n--- Add Student Record ---\n";
    cout << "ID: ";
    cin >> stu.ID;
    cin.ignore();
    cout << "Name: ";
    getline(cin, stu.name);
    cout << "Address: ";
    getline(cin, stu.address);
    cout << "Parent Name: ";
    getline(cin, stu.parentName);
    cout << "Class: ";
    getline(cin, stu.className);
    cout << "Phone: ";
    cin >> stu.phone;

    file << stu.ID << "|" << stu.name << "|" << stu.address << "|"
         << stu.parentName << "|" << stu.className << "|" << stu.phone << "\n";

    file.close();
    cout << "Student added successfully!\n";
}

void searchStudent()
{
    ifstream file("record.txt");
    if (!file)
    {
        cout << "No student records found.\n";
        return;
    }

    string id;
    cout << "\n--- Search Student ---\n";
    cout << "Enter ID: ";
    cin >> id;

    Student stu;
    bool found = false;
    string line;

    while (getline(file, line))
    {
        size_t pos = 0;
        vector<string> data;
        while ((pos = line.find("|")) != string::npos)
        {
            data.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        data.push_back(line);

        if (data.size() == 6 && data[0] == id)
        {
            stu.ID = data[0];
            stu.name = data[1];
            stu.address = data[2];
            stu.parentName = data[3];
            stu.className = data[4];
            stu.phone = stoull(data[5]);

            found = true;
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << stu.ID << "\n";
            cout << "Name: " << stu.name << "\n";
            cout << "Address: " << stu.address << "\n";
            cout << "Parent: " << stu.parentName << "\n";
            cout << "Class: " << stu.className << "\n";
            cout << "Phone: " << stu.phone << "\n";
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    file.close();
}

void modifyStudent()
{
    ifstream file("record.txt");
    if (!file)
    {
        cout << "No student records found.\n";
        return;
    }

    vector<string> lines;
    string line, id;
    cout << "\n--- Modify Student ---\n";
    cout << "Enter ID to modify: ";
    cin >> id;

    bool found = false;
    while (getline(file, line))
    {
        if (line.rfind(id + "|", 0) == 0)
        {
            Student stu;
            cout << "Enter new details:\n";
            cout << "New ID: ";
            cin >> stu.ID;
            cin.ignore();
            cout << "New Name: ";
            getline(cin, stu.name);
            cout << "New Address: ";
            getline(cin, stu.address);
            cout << "New Parent Name: ";
            getline(cin, stu.parentName);
            cout << "New Class: ";
            getline(cin, stu.className);
            cout << "New Phone: ";
            cin >> stu.phone;

            lines.push_back(stu.ID + "|" + stu.name + "|" + stu.address + "|" +
                            stu.parentName + "|" + stu.className + "|" +
                            to_string(stu.phone));
            found = true;
        }
        else
        {
            lines.push_back(line);
        }
    }
    file.close();

    ofstream out("record.txt");
    for (auto &l : lines)
        out << l << "\n";
    out.close();

    if (found)
        cout << "Student modified successfully.\n";
    else
        cout << "Student not found.\n";
}

void deleteStudent()
{
    ifstream file("record.txt");
    if (!file)
    {
        cout << "No student records found.\n";
        return;
    }

    vector<string> lines;
    string line, id;
    cout << "\n--- Delete Student ---\n";
    cout << "Enter ID to delete: ";
    cin >> id;

    bool deleted = false;
    while (getline(file, line))
    {
        if (line.rfind(id + "|", 0) != 0)
        {
            lines.push_back(line);
        }
        else
        {
            deleted = true;
        }
    }
    file.close();

    ofstream out("record.txt");
    for (auto &l : lines)
        out << l << "\n";
    out.close();

    if (deleted)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

void addMarksheet()
{
    ofstream file("marksheet.txt", ios::app);
    if (!file)
    {
        cout << "Error opening marksheet file.\n";
        return;
    }

    Marksheet mark;
    cout << "\n--- Add Marksheet ---\n";
    cout << "Enter Student ID: ";
    cin >> mark.ID;

    for (int i = 0; i < 6; i++)
    {
        cin.ignore();
        cout << "Subject " << i + 1 << ": ";
        getline(cin, mark.subject[i]);
        cout << "Theory Max, Practical Max: ";
        cin >> mark.theoryMax[i] >> mark.practicalMax[i];
        cout << "Theory Marks, Practical Marks: ";
        cin >> mark.theoryMarks[i] >> mark.practicalMarks[i];
    }

    file << mark.ID;
    for (int i = 0; i < 6; i++)
    {
        file << "|" << mark.subject[i] << "|" << mark.theoryMax[i] << "|"
             << mark.practicalMax[i] << "|" << mark.theoryMarks[i] << "|"
             << mark.practicalMarks[i];
    }
    file << "\n";
    file.close();
    cout << "Marksheet added successfully!\n";
}

void searchMarksheet()
{
    ifstream file("marksheet.txt");
    if (!file)
    {
        cout << "No marksheets found.\n";
        return;
    }

    string id;
    cout << "\n--- Search Marksheet ---\n";
    cout << "Enter Student ID: ";
    cin >> id;

    string line;
    bool found = false;
    while (getline(file, line))
    {
        if (line.rfind(id + "|", 0) == 0)
        {
            found = true;
            Marksheet mark;
            vector<string> data;
            size_t pos = 0;
            while ((pos = line.find("|")) != string::npos)
            {
                data.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            data.push_back(line);

            mark.ID = data[0];
            int idx = 1;
            int total = 0, obtained = 0;
            cout << "\nMarksheet for ID: " << mark.ID << "\n";
            for (int i = 0; i < 6; i++)
            {
                mark.subject[i] = data[idx++];
                mark.theoryMax[i] = stoi(data[idx++]);
                mark.practicalMax[i] = stoi(data[idx++]);
                mark.theoryMarks[i] = stoi(data[idx++]);
                mark.practicalMarks[i] = stoi(data[idx++]);

                cout << mark.subject[i] << ": "
                     << mark.theoryMarks[i] << "/" << mark.theoryMax[i]
                     << " T, " << mark.practicalMarks[i] << "/" << mark.practicalMax[i] << " P\n";

                total += mark.theoryMax[i] + mark.practicalMax[i];
                obtained += mark.theoryMarks[i] + mark.practicalMarks[i];
            }

            double percent = total ? (obtained * 100.0 / total) : 0;
            cout << "Total: " << obtained << "/" << total << "\n";
            cout << "Percentage: " << percent << "%\n";
            break;
        }
    }

    if (!found)
        cout << "Marksheet not found.\n";

    file.close();
}

void menu()
{
    int choice;
    while (true)
    {
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

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            modifyStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            addMarksheet();
            break;
        case 6:
            searchMarksheet();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }
}

int main()
{
    menu();
    return 0;
}
