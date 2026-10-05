void FeedbackManager::trackFeedback() {
    map<string, int> feedbackCount;
    for (size_t i = 0; i < feedbackList.size(); i++) {
        feedbackCount[feedbackList[i].getCategory()]++;
    }
    cout << "Feedback Summary:" << endl;
    for (map<string, int>::iterator it = feedbackCount.begin(); ! (it == feedbackCount.end()); it++) {
        cout << "Category: " << it->first << ", Count: " << it->second << endl;
    }
}