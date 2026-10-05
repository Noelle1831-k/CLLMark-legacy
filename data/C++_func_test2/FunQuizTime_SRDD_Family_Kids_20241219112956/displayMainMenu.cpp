void QuizApp::displayMainMenu() {
    int choice;
    cout << "Welcome to FunQuizTime!" << endl;
    cout << "Please choose a subject:" << endl;
    cout << "1. Math" << endl;
    cout << "2. Science" << endl;
    cout << "3. History" << endl;
    cout << "4. Language Arts" << endl;
    cout << "5. General Knowledge" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    subject.loadQuizzes(choice);  
    startQuiz();
}