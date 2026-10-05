void FeedbackManager::displayAllFeedback() {
    for (size_t i = 0; i < feedbackList.size(); i++) {
        feedbackList[i].displayFeedback();
    }
}