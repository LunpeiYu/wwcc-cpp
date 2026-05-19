#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
using namespace std;

// Recipe structure stores
struct Recipe{
    string recipeName;
    vector<string> ingredients;
    vector<string> steps;
};
// FUNCTION PROTOTYPES
void addRecipe (vector<Recipe> &recipes);
void printRecipe(const Recipe &r);
void displayRecipes(const vector<Recipe> &recipes);
string toLowerString(string s);
void searchRecipes(const vector<Recipe> &recipes);
void removeRecipes(vector<Recipe> &recipes);
void showStatistics(const vector<Recipe> &recipes);

// MAIN FUNCTION
int main() {

    vector<Recipe> recipes;

    int choice;

    do{

        cout << "\nDYNAMIC RECIPE MANAGER" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add Recipe" << endl;
        cout << "2. Display All Recipes" << endl;
        cout << "3. Search Recipe" << endl;
        cout << "4. Remove Recipe" << endl;
        cout << "5. Show Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number (1-6)!" << endl;
            continue;
        }

        switch (choice) {

            case 1:
                addRecipe(recipes);
                break;

            case 2:
                displayRecipes(recipes);
                break;

            case 3:
                searchRecipes(recipes);
                break;

            case 4:
                removeRecipes(recipes);
                break;
            
            case 5:
                showStatistics(recipes);
                break;

            case 6:
                cout << "\nGoodbye!";
                break;
        
            default:
                cout << "\nInvalid choice. Please enter 1-6!" << endl;
                break;
        }

    } while (choice != 6);
            
    return 0;
}

// FUNCTION DEFINITIONS
// Add a recipe into the collection
void addRecipe (vector<Recipe> &recipes) {

    Recipe r;

    cin.ignore();

    cout << "\nEnter recipe name: ";    
    getline(cin, r.recipeName);

    int ingredientsCount;

    cout << "\nHow many ingredients? ";

    while (true) {
        cin >> ingredientsCount;

        if (!cin.fail() && ingredientsCount > 0) break;

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter a non-zero positive integer: ";
    }    
    cin.ignore();

    for (int i = 0; i < ingredientsCount; i++) {

        string ingredient;
        cout << "Enter ingredient " << i +1 << ": ";

        getline(cin, ingredient);

        r.ingredients.push_back(ingredient);       
    }
    
    int stepCount;

    cout << "\nHow many steps? ";

    while (true) {
        cin >> stepCount;

        if (!cin.fail() && stepCount > 0) break;

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter a non-zero positive integer: ";
    }    
    cin.ignore();

    for (int i = 0; i < stepCount; i++) {
        
        string step;
        cout << "Enter step " << i + 1 << ": ";

        getline(cin, step);

        r.steps.push_back(step);
    }

    recipes.push_back(r);

    cout << "\nRecipe added successfully!" << endl;

}

// Print one recipe in formatted style
void printRecipe(const Recipe &r) {
    cout << "\nRecipe: " << r.recipeName << endl;
    cout << "\nIngredients:" << endl;

    for (int i = 0; i < r.ingredients.size(); i++) {
        cout << i + 1 << ". " << r.ingredients.at(i) << endl;
    }

    cout << "\nSteps:" << endl;

    for (int i = 0; i < r.steps.size(); i++) {
        cout << i + 1 << ". " << r.steps.at(i) << endl;
    }
}

// Display all recipes in collection
void displayRecipes(const vector<Recipe> &recipes) {

    if (recipes.empty()) {
        cout << "No recipes found!" << endl;
        return;
    }

    cout << "\n========== ALL RECIPES ==========" << endl;

    for (int i = 0; i < recipes.size(); i++) {
        
        printRecipe(recipes.at(i));
    }
}

// Convert string to lowercase (for case-insensitive search)
string toLowerString(string s) {

    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;
}

// Search recipes by partial match (name or ingredients)
void searchRecipes(const vector<Recipe> &recipes) {

    if (recipes.empty()) {
        cout << "\nNo recipes available!" << endl;
        return;
    }

    cin.ignore();

    string searchRecipe;

    cout << "\nEnter keyword to search recipe: ";
    getline(cin, searchRecipe);

    searchRecipe = toLowerString(searchRecipe);

    bool found = false;

    for (int i = 0; i < recipes.size(); i++) {

        bool match = false;
        
        string name = toLowerString(recipes.at(i).recipeName);

        if (name.find(searchRecipe) != string::npos) {
            match = true;
        }

        for (int j = 0; j < recipes.at(i).ingredients.size(); j++) {

            string ingredient = toLowerString(recipes.at(i).ingredients.at(j));
           
            if (ingredient.find(searchRecipe) != string::npos) {
                match = true;
                break;
            }
        }

        if(match) {
            printRecipe(recipes.at(i));
            found = true;
        }
    } 

    if(!found) {
        cout << "\nNo matching recipes found!" << endl;
    }
}

// Remove recipe by partial name match
void removeRecipes(vector<Recipe> &recipes) {

    if (recipes.empty()) {
        cout << "No recipes to remove!" << endl;
        return;
    }

    cin.ignore();

    string removeRecipe;

    cout << "\nEnter recipe name to remove: ";
    getline(cin, removeRecipe);

    removeRecipe = toLowerString(removeRecipe);

    bool found = false;

    for (int i = 0; i < recipes.size(); i++) {
        
        string name = toLowerString(recipes.at(i).recipeName);

        if(name.find(removeRecipe) != string::npos) {
            cout << "\nRemoving recipe: " << recipes.at(i).recipeName << endl;

            recipes.erase(recipes.begin() + i);

            cout << "\nRecipe removed successfully!" << endl;

            found = true;
            break;
        }
    }
    if(!remove) {
        cout << "\nNo matching recipe found!" << endl;
    }

}

// Show statistics of recipe collection
void showStatistics(const vector<Recipe> &recipes) {

    if (recipes.empty()) {
        cout << "\nNo recipes available!" << endl;
        return;
    }

    int totalRecipes = recipes.size();
    int totalIngredients = 0;
    int totalSteps = 0;

    for (int i = 0; i < recipes.size(); i++) {
        
        totalIngredients += recipes.at(i).ingredients.size();
        totalSteps += recipes.at(i).steps.size();
    }

    double averageIngredients = (double)totalIngredients / totalRecipes;
    double averageSteps = (double)totalSteps / totalRecipes;

    cout << "\nCOLLECTION STATISTICS" << endl;
    cout << "---------------------" << endl;
    cout << "Total recipes: " << totalRecipes << endl;
    cout << fixed << setprecision(2);
    cout << "Average ingredients per recipe: " << averageIngredients << endl;
    cout << "Average steps per recipe: " << averageSteps << endl;
}



