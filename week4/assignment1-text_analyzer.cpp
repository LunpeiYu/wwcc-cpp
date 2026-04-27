#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {

    // Program title
    cout << "TEXT ANALYZER" << endl;
    cout << "-------------" << endl;

    // User input
    string sentence;
    cout << "Enter a sentence or paragraph:" << endl;
    getline(cin, sentence);

    // Variables for analysis
    stringstream ss(sentence);
    string word;

    int wordCount = 0;
    string longestWord = "";
    int lengthSum = 0;

    // Count words, find longest word, calculate the length of total letters
    while(ss >> word) {

        wordCount++;

        // Remove punctuation before comparing length
        string noPunctWord = word;

        noPunctWord.erase(
            remove_if(noPunctWord.begin(), noPunctWord.end(),::ispunct),
            noPunctWord.end()
        );

        // Add no punctuation word length
        lengthSum += noPunctWord.length();

        // Find longest word
        if (noPunctWord.length() > longestWord.length()) {
            longestWord = noPunctWord;
        }
    }

    // Calculate average word length
    double averageWordLength = 0;
    if(wordCount > 0) {
        averageWordLength = static_cast<double>(lengthSum) / wordCount;
    }        

    // Count number of sentences
    int sentenceCount = 0;
    bool sentenceEnd = false;

    for (char ch : sentence) {
        if (ch == '.' || ch == '!' || ch == '?') {
            if (!sentenceEnd) {
                sentenceCount++;
                sentenceEnd = true;
            }
        }
        else {
            sentenceEnd = false;
        }
    }
    
    // Create uppercase and lowercase copies
    string originalSentence = sentence;
    string upperSentence = sentence;
    string lowerSentence = sentence;

    // Convert to uooercase
    for (char &c : upperSentence) {
        c = toupper(c);
    }

    // Convert to lowercase
    for (char &c : lowerSentence) {
        c = tolower(c);
    }
       
    // Output results
    cout << "\nAnalysis:" << endl;
    cout << "  Characters (with spaces): " << sentence.length() << endl;
    cout << "  Word count:               " << wordCount << endl;
    cout << "  Longest word:             " << longestWord << endl;
    cout << "  Average word length:      " << fixed << setprecision(1) << averageWordLength << " characters"<< endl;
    cout << "  Sentence count:           " << sentenceCount << endl;
    cout << "\nUppercase:" << endl;
    cout << "  " <<upperSentence << endl;
    cout << "\nLowercase:" << endl;
    cout << "  " << lowerSentence << endl;

    return 0;
}