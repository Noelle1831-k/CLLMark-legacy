void Quiz::startQuiz() {
    cout << "Quiz Time!" << endl;
    cout << question << endl;
    cout << "Enter your answer: ";
    string answer;
    cin >> answer;
    checkAnswer(answer);
}