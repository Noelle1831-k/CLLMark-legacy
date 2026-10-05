void UserInterface::displayRecommendations(const vector<Vendor>& recommendations) {
    cout << "Recommended Vendors:" << endl;
    for (size_t i = 0; i < recommendations.size(); ++i) {
        cout << recommendations[i].getName() << " - " << recommendations[i].getType() << " - Rating: " << recommendations[i].getRating() << endl;
    }
}