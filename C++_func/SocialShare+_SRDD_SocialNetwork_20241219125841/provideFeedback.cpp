void Collaboration::provideFeedback(const std::string& feedback) {
    feedbacks.push_back(feedback);
    cout << "Feedback provided for the project.\n";
}