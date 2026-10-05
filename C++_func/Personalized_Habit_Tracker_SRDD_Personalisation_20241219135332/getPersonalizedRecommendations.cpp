void User::getPersonalizedRecommendations() {
    if (habits.empty()) {
        cout << "No habits to analyze.\n";
        return;
    }
    for (int i = 0; i < habits.size(); i++) {
        cout << "Recommendation for " << habits[i].getName() << ": " << habits[i].getRecommendation() << endl;
    }
}