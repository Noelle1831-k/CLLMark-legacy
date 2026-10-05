void Visualization::showExplanation(vector<string>& recommendations) {
    cout << "Showing explanation for recommendations..." << endl;
    for (int i = 0; i < recommendations.size(); i++) {
        cout << "Explanation for: " << recommendations[i] << endl;
    }
}