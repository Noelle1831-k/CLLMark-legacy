void FeedbackForm::createForm() {
    cout << "Enter the title of the feedback form: ";
    getline(cin, formTitle);
    int numQuestions;
    cout << "Enter the number of questions: ";
    cin >> numQuestions;
    cin.ignore();
    for (int i = 0; i < numQuestions; i++) {
        string question;
        cout << "Enter question " << i + 1 << ": ";
        getline(cin, question);
        questions.push_back(question);
    }
    cout << "Feedback form created successfully!" << endl;
}