void Question::generateQuestion(const string& language, int difficulty, WordDatabase& database) {
    string word = database.getRandomWord(language, difficulty);
    correctAnswer = database.getSynonym(word, language, difficulty);
    options.push_back(correctAnswer);
    int i;
    for (i = 0; i < 3; i++) {
        options.push_back(database.getSynonym(database.getRandomWord(language, difficulty), language, difficulty));
    }
    random_shuffle(options.begin(), options.end());
    cout << "Question: What is the synonym of " << word << "?" << endl;
    for (i = 0; i < (int)options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}