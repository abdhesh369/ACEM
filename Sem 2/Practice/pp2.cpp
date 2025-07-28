#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Cricketer {
private:
    string name, role, grade, battingStyle, bowlingStyle;
    string domesticTeam, nplTeam, lastODI, lastT20I;

public:
    Cricketer(string n, string r, string g, string bat, string bowl,
              string dom, string npl, string odi, string t20i) {
        name = n;
        role = r;
        grade = g;
        battingStyle = bat;
        bowlingStyle = bowl;
        domesticTeam = dom;
        nplTeam = npl;
        lastODI = odi;
        lastT20I = t20i;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "\n==============================\n";
        cout << "Name: " << name << "\n";
        cout << "Role: " << role << "\n";
        cout << "Contract Grade: " << grade << "\n";
        cout << "Batting Style: " << battingStyle << "\n";
        cout << "Bowling Style: " << bowlingStyle << "\n";
        cout << "Domestic Team: " << domesticTeam << "\n";
        cout << "NPL Team: " << nplTeam << "\n";
        cout << "Last ODI Played: " << lastODI << "\n";
        cout << "Last T20I Played: " << lastT20I << "\n";
        cout << "==============================\n";
    }
};

string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    vector<Cricketer> players = {
        Cricketer("Dipendra Singh Airee", "All-rounder (Vice-Captain)", "A", "Right-handed", "Right-arm off break", "Nepal Police Club", "Sudurpaschim Royals", "2025", "2025"),
        Cricketer("Rohit Paudel", "Batsman (Captain)", "A", "Right-handed", "Right-arm off break", "APF Club", "Lumbini Lions", "2025", "2025"),
        Cricketer("Sandeep Lamichhane", "Bowler", "A", "Right-handed", "Right-arm Leg break", "Bagmati Province", "Biratnagar Kings", "2025", "2025"),
        Cricketer("Sompal Kami", "Bowler", "A", "Right-handed", "Right-arm Fast medium", "Tribhuwan Army Club", "Karnali Yaks", "2025", "2025"),
        Cricketer("Aasif Sheikh", "Wicketkeeper-Batsman", "A", "Right-handed", "N/A", "APF Club", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Gulsan Jha", "All-rounder", "B", "Left-handed", "Right-arm medium", "Nepal Police Club", "Karnali Yaks", "2025", "2025"),
        Cricketer("Karan KC", "Bowler", "B", "Right-handed", "Right-arm Fast medium", "APF Club", "Kathmandu Gurkhas", "2025", "2025"),
        Cricketer("Lalit Rajbanshi", "Bowler", "B", "Right-handed", "Slow left-arm orthodox", "Nepal Police Club", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Anil Kumar Sah", "Wicketkeeper-Batsman", "B", "Right-handed", "N/A", "Madhesh Province", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Bhim Sharki", "Batsman", "B", "Right-handed", "N/A", "Nepal Army Club", "Kathmandu Gorkhas", "2025", "2025"),
        Cricketer("Kushal Bhurtel", "Batsman", "C", "Right-handed", "Right-arm Leg break", "Nepal Police Club", "Pokhara Avengers", "2025", "2025"),
        Cricketer("Aarif Sheikh", "All-rounder", "C", "Right-handed", "Right-arm medium", "Nepal Police Club", "Sudurpaschim Royals", "2025", "2025"),
        Cricketer("Kushal Malla", "All-rounder", "C", "Left-handed", "Slow left-arm orthodox", "Nepal Army Club", "Chitwan Rhinos", "2025", "2025"),
        Cricketer("Rijan Dhakal", "Bowler", "C", "Right-handed", "Left-arm medium", "Bagmati Province", "Chitwan Rhinos", "2025", "2025"),
        Cricketer("Nandan Yadav", "Bowler", "C", "Right-handed", "Right-arm medium", "Bagmati Province", "Karnali Yaks", "2025", "2025"),
        Cricketer("Mayan Yadav", "Bowler", "C", "Right-handed", "N/A", "Madhesh Province", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Dev Khanal", "Bowler", "C", "Right-handed", "N/A", "Lumbini Province", "Karnali Yaks", "2025", "2025"),
        Cricketer("Subh Kansakar", "All-rounder", "C", "Right-handed", "N/A", "Bagmati Province", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Arjun Kumal", "Bowler", "C", "Right-handed", "N/A", "Gandaki Province", "Sudurpaschim Royals", "2025", "2025"),
        Cricketer("Basir Ahamad", "All-rounder", "D", "Left-handed", "Slow left-arm orthodox", "Nepal Army Club", "Biratnagar Kings", "2025", "2025"),
        Cricketer("Bibek Yadav", "Bowler", "D", "Right-handed", "Right-arm medium", "Nepal Army Club", "Lumbini Lions", "2025", "2025"),
        Cricketer("Sagar Dhakal", "Bowler", "D", "Right-handed", "Slow left-arm orthodox", "Nepal Police Club", "Pokhara Avengers", "2022", "2024"),
        Cricketer("Surya Tamang", "Bowler", "D", "Left-handed", "Slow left-arm orthodox", "Bagmati Province", "Lumbini Lions", "2024", "2024"),
        Cricketer("Shahab Alam", "Bowler", "D", "Left-handed", "Slow left-arm orthodox", "Tribhuwan Army Club", "Kathmandu Gurkhas", "2022", "2022"),
        Cricketer("Dipesh Kandel", "Bowler", "D", "Left-handed", "Slow left-arm orthodox", "Koshi Province", "Kathmandu Gurkhas", "2022", "2022"),
        Cricketer("Aakash Chand", "Bowler", "D", "Right-handed", "Right-arm medium", "Tribhuwan Army Club", "Pokhara Avengers", "2024", "2024"),
        Cricketer("Avinash Bohara", "Bowler", "D", "Right-handed", "Right-arm medium", "APF Club", "Sudurpaschim Royals", "2024", "2024"),
        Cricketer("Pratis GC", "Bowler", "D", "Right-handed", "Left-arm medium", "Bagmati Province", "Biratnagar Kings", "2024", "2024"),
        Cricketer("Hemant Dhami", "Bowler", "D", "Right-handed", "Right-arm medium", "Sudurpashchim Province", "Janakpur Bolts", "2024", "2024"),
        Cricketer("Rupesh Singh", "All-rounder", "EC", "Right-handed", "Right-arm medium", "Madhesh Province", "Janakpur Bolts", "2025", "2025"),
        Cricketer("Santosh Yadav", "Bowler", "EC", "Left-handed", "Slow left-arm orthodox", "Lumbini Province", "N/A", "N/A", "N/A"),
        Cricketer("Arjun Gharti", "Wicketkeeper-Batsman", "EC", "Right-handed", "N/A", "Karnali Province", "Karnali Yaks", "N/A", "N/A")
    };

    cout << "=== Nepali Cricketer Contracted Players 2025 ===\n";
    cout << "Type 'exit' to quit.\n";

    while (true) {
        cout << "\nEnter player name to search: ";
        string input;
        getline(cin, input);

        if (toLower(input) == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        bool found = false;
        string searchName = toLower(input);

        for (int i = 0; i < players.size(); i++) {
            if (toLower(players[i].getName()).find(searchName) != string::npos) {
                players[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "Player is not in contract list \"" << input << "\".\n";
        }
    }

    return 0;
}