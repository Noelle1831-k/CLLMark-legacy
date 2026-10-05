void FeedbackForm::displayForm() {
    cout << "Form Title: " << formTitle << endl;
    for (size_t i = 0; i < questions.size(); i++) {
        cout << i + 1 << ". " << questions[i] << endl;
    }
}