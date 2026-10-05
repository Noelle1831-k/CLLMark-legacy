void Feedback::collectFeedback(const string &feedback) {
    feedbackList.push_back(feedback);
    cout << "Feedback collected: " << feedback << endl;
}