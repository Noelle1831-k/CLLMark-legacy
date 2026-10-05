void QuizApp::startQuiz() {
    int level;
    cout << "Choose difficulty level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "Enter your choice: ";
    cin >> level;
    subject.chooseDifficulty(level);  
    vector<Question> questions = subject.loadQuestions();  
    for (int i = 0; ; ) {
        if (!((i <= questions.size() && i != questions.size()))) {
            break;
        }
        bool answerCorrect = questions[i].askQuestion();
        giveFeedback(i, answerCorrect);
        i++;
    }
    showResults();
}