void Feedback::viewFeedback() const {
    cout << "Feedback List:" << endl;
    for (const auto &fb : feedbackList) {
        cout << "- " << fb << endl;
    }
}