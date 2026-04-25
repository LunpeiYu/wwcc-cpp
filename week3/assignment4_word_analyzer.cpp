#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int countVowels(string word);
int countConsonants(string word);
char firstLetter(string word);
string reverse(string word);
bool isPalindrome(string word);

// Main Function
int main() {
    
    string word;
    char anotherWord = 'y';
    
    // Loop for multiple word analysis
    while (anotherWord == 'y' || anotherWord == 'Y') {
        
        cout << "\nEnter a word: ";
        cin >> word;

        cout << "\nWord Analysis:\n";
        cout << "-------------" << endl;
        cout << "Original word: " << word << endl;

        cout << "Number of vowels: " << countVowels(word) << endl;
        cout << "Number of consonants: " << countConsonants(word) << endl;
        cout << "First letter: " << firstLetter(word) << endl;
        cout << "Reversed: " << reverse(word) << endl;

        if (isPalindrome(word)) {
            cout << "Is palindrome: Yes" << endl;
        }
        else {
            cout << "Is palindrome: No" << endl;
        }
        
        cout << "\nWould you like to analyze another word? (y/n): ";
        cin >> anotherWord;
        
        while (anotherWord != 'y' && anotherWord != 'Y' && anotherWord != 'n' && anotherWord != 'N') {
            cout << "Invalid input. Please enter y or n: ";
            cin >> anotherWord;
        }
    } 
    return 0;
}

// Function Counts vowels(a, e, i, o, u)
int countVowels(string word) {
    int count = 0;

    for (char ch : word) {
        ch = tolower(ch);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count ++;
        }
    }
    return count;
}

// Function Counts Consonants(letters that are not vowels)
int countConsonants(string word) {
    int count = 0;

    for (char ch : word) {
        ch = tolower(ch);

        if (isalpha(ch)){
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                count++;
            }
        }
    }
    return count;
}

// Function Finds the first letter of the word
char firstLetter(string word) {
    for (char ch : word) {
        if (isalpha(ch)) {
            return ch;
        }
    }
    return '\0';   
}

// Function Returns the reversed word
string reverse(string word) {
    string reverseWord = "";

    for (int i = word.length() - 1; i >= 0; i--) {
        reverseWord += word[i];
    }
    return reverseWord;
}

// Function Checks if the word is a palindrom
bool isPalindrome(string word) {
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if ((tolower(word[left])) != tolower(word[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}



