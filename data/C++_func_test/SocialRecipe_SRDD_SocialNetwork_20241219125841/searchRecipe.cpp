void Recipe::searchRecipe() {
    string keyword;
    cout << "Enter a keyword to search for recipes: ";
    cin >> keyword;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Search results:" << endl;
    for (map<string, string>::iterator it = recipes.begin(); it != recipes.end(); it++) {
        if (it->first.find(keyword) != string::npos) {
            cout << it->first << endl;
        }
    }
}