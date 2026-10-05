void FeedbackManager::categorizeFeedback() {
    map<string, vector<Feedback>> categorizedFeedback;
    for (size_t i = 0; i < feedbackList.size(); i++) {
        categorizedFeedback[feedbackList[i].getCategory()].push_back(feedbackList[i]);
    }
    for (map<string, vector<Feedback>>::iterator it = categorizedFeedback.begin(); it != categorizedFeedback.end(); it++) {
        cout << "Category: " << it->first << endl;
        for (size_t j = 0; j < it->second.size(); j++) {
            it->second[j].displayFeedback();
            cout << "----------------------" << endl;
        }
    }
}