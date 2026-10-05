void Collaboration::listFeedback() const {
    cout << "Feedback for project " << projectName << ":\n";
    for (size_t i = 0; i < feedbacks.size(); i++) {
        cout << "- " << feedbacks[i] << "\n";
    }
}