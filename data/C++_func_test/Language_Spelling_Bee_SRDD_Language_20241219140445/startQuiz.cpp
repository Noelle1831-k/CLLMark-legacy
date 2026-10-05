void QuizManager::startQuiz() {
    string word = wordDB->getRandomWord();
    string answer;
    cout << "Spell the word: " << word << endl;
    cin >> answer;
    evaluateAnswer(word, answer);
}