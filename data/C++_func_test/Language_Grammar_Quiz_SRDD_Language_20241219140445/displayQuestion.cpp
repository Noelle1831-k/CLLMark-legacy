void Quiz::displayQuestion(int index) {
    cout << "Question " << index + 1 << ": " << questions[index].getQuestionText() << endl;
    vector<string> options = questions[index].getOptions();
    for (int i = 0; i < options.size(); i++) {
        cout << static_cast<char>('A' + i) << ". " << options[i] << endl;
    }
}