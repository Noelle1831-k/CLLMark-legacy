void WordDatabase::loadWords(const string& language, int difficulty) {
    words["English"][1] = {"cat", "dog", "bird", "fish"};
    words["English"][2] = {"elephant", "giraffe", "kangaroo", "rhinoceros"};
    words["English"][3] = {"xylophone", "quizzical", "mnemonic", "onomatopoeia"};
    words["Spanish"][1] = {"gato", "perro", "pájaro", "pez"};
    words["Spanish"][2] = {"elefante", "jirafa", "canguro", "rinoceronte"};
    words["Spanish"][3] = {"xilófono", "capicúa", "memorándum", "onomatopeya"};
    if (words.find(language) != words.end() && words[language].find(difficulty) != words[language].end()) {
        currentLanguage = language;
        currentDifficulty = difficulty;
        srand(time(0));
    } else {
        cout << "Error: Language or difficulty level not found." << endl;
        exit(1); 
    }
}