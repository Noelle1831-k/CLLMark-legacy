void FeedbackForm::editForm() {
    cout << "Editing form: " << formTitle << endl;
    displayForm();
    int questionIndex;
    cout << "Enter the question number to edit: ";
    cin >> questionIndex;
    cin.ignore();
    if (questionIndex > 0 && questionIndex <= questions.size()) {
        cout << "Enter the new question: ";
        getline(cin, questions[questionIndex - 1]);
        cout << "Question updated successfully!" << endl;
    } else {
        cout << "Invalid question number!" << endl;
    }
}