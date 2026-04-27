# include <iostream>
using namespace std;

// Function Prototype
// Converts numeric score into letter grade (A,B,C,D,F)
char getLetterGrade(double score);

// Main Function
int main() {
    const int NumQuizzes = 5;
    int scores[NumQuizzes];
    
    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "------------------" << endl;

    // User input quiz scores
    for (int i = 0; i < NumQuizzes; i++) {
        cout << "Enter score for Quiz " << i+1 << " (0-100): ";
        cin >> scores[i];
    }
    // Display quiz result
    cout << "\nQuiz Result:" << endl;
    for (int i = 0; i < NumQuizzes; i++) {
        cout << "Quiz " << i+1 << ": " << scores[i] << " (" << getLetterGrade(scores[i]) << ")" << endl;
    }
    // Calculate statistics
    // Initialization
    int sum = 0;
    int highestScore = scores[0];
    int lowestScore = scores[0];
    int highestScoreQuizIndex = 0;
    int lowestScoreQuizIndex = 0;

    // Find the highest and lowest scores
    for (int i = 0; i < NumQuizzes; i++) {
        sum += scores[i];

        if (scores[i] > highestScore) {
            highestScore = scores[i];
            highestScoreQuizIndex = i;
        }

        if (scores[i] < lowestScore) {
            lowestScore = scores[i];
            lowestScoreQuizIndex = i;
        }
    }

    // Calculate average (floating-point division)
    double average = static_cast<double>(sum) / NumQuizzes;
    
    // Display statistics
    cout << "\nStatistics:" << endl;
    cout << "Average score: " << average << endl;
    cout << "Hignest score: " << highestScore << " (Quiz " << highestScoreQuizIndex + 1<< ")" << endl;
    cout << "lowest score: " << lowestScore << " (Quiz " << lowestScoreQuizIndex + 1 << ")" << endl;
    cout << "Overall grade: " << getLetterGrade(average) << endl;
    
    // Grade distribution
    int gradeCount[5] = {0};

    for (int i = 0; i < NumQuizzes; i++) {
        char grade = getLetterGrade(scores[i]);

        if (grade == 'A') {
            gradeCount[0]++;
        }
        else if (grade == 'B') {
            gradeCount[1]++;
        }
        else if (grade == 'C') {
            gradeCount[2]++;
        }
        else if (grade == 'D') {
            gradeCount[3]++;
        }
        else {
            gradeCount[4]++;
        }        
    }

    char letters[5] = {'A', 'B', 'C', 'D', 'F'};
    
    cout << "\nGrade Distribution:" << endl;    
    for (int i = 0; i < 5; i++) {
        cout << letters[i] << ": " << gradeCount[i] << endl;
    }
    
    return 0;

}

// Function Definition
// Takes score and returns letter grade
char getLetterGrade(double score) {

    if (score >= 90) {
        return 'A';
    }
    else if (score >= 80) {
        return 'B';
    }
    else if (score >= 70) {
        return 'C';
    }
    else if (score >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}



    