#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    // --- Read input file ---
    ifstream inFile("grades.txt");

    // BUG 1: program did not check whether input file opened successfully.
    // FIX: added file open validation to prevent reading from invalid stream.
    if (!inFile) {
        cerr << "Error: cannot open file for reading!" << endl;
        return 1;
    }

    cout << "Reading records from grades.txt..." << endl;

    vector<Student> students;
    string line; 

    // BUG 2: using eof() loop causes incorrect reading behavior.
    // FIX: replaced with getline() loop which correctly controls file reading.
    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') continue;

       // BUG 3: stringstream declared outside or reused incorrectly.
       // FIX: create a fresh stringstream for each line to avoid data contamination.
        stringstream ss(line);  

        Student s;
        ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3;

        s.high = max({s.g1, s.g2, s.g3});
        s.low  = min({s.g1, s.g2, s.g3});

        int total = s.g1 + s.g2 + s.g3;
        
        // BUG 4: integer division caused loss of decimal precision in average calculation.
        // FIX: cast to double to preserve decimal accuracy.
        s.average = static_cast<double>(total) / 3.0;  

        students.push_back(s);
    }
    inFile.close();

    cout << students.size() << " students loaded." << endl << endl;

    // --- Write report ---
    // BUG 5: output file overwrite previous content each run.
    // FIX: changed to append mode to preserve previous reports.
    ofstream outFile("grade_report.txt", ios::app); 

    // --- Display to console and write to file ---
    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(20, '-') << endl;

        out << left << setw(20) << "Name"
            << right
            << setw(6)  << "Avg"
            << setw(10)  << "High"
            << setw(6)  << "Low"
            << endl;
        out << string(20, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;

            // BUG 6: setw() was set outside loop and only applied to first output field.
            // FIX: moved setw() to each column inside loop for proper alignment.
            out << left << setw(20) << name

                // BUG 7: numeric were left-aligned instead of right-aligned.
                // FIX: changed numeric output columns to right alignment for proper formatting.
                << right
                << setw(7)  << fixed << setprecision(1) << s.average
                << setw(7)  << s.high
                << setw(7)  << s.low
                << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = classTotal / students.size();

        out << endl << "CLASS STATISTICS" << endl;
        out << string(20, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   "
            << students[topIdx].lastName << ", "
            << students[topIdx].firstName
            << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   "
            << students[lowIdx].lastName << ", "
            << students[lowIdx].firstName
            << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}