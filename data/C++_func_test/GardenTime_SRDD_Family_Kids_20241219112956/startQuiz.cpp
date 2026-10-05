void Quiz::startQuiz() {
    printf("Quiz Time!\n");
    cout << question << endl;
    printf("Enter your answer: ");
    string answer;
    cin >> answer;
    checkAnswer(answer);
}