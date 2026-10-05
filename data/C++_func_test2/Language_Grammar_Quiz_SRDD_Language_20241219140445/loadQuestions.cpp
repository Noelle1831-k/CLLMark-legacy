void Quiz::loadQuestions(const string& language, const string& difficulty) {
    questions.clear();
    string filename = language + "_" + difficulty + "_questions.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to load questions for the selected language and difficulty." << endl;
        exit(1);
    }
    string questionText, correctAnswer, option;
    vector<string> options;
    while (getline(file, questionText)) {
        options.clear();
        for (int i = 0; i < 4; i++) {
            getline(file, option);
            options.push_back(option);
        }
        getline(file, correctAnswer);
        questions.emplace_back(questionText, options, correctAnswer);
    }
    file.close();
}