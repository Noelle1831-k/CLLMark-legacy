void Question::displayQuestion() {
    cout << questionText << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}