void Visualization::displayDashboard(const vector<string> &insights) {
    cout << "---------- Workspace Optimization Dashboard ----------" << endl;
    for (size_t i = 0; i < insights.size(); ++i) {
        cout << insights[i] << endl;
        if (i != insights.size() - 1) {
            cout << "------------------------------------------------------" << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}