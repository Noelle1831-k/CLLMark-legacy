void Meeting::getFeedbackSummary() const {
    cout << "Feedback for Meeting: " << title << endl;
    cout << "Date: " << date << endl;
    for (const auto &feedback : feedbacks) {
        feedback.displayFeedback();
    }
}