void Visualization::displayDashboard(const vector<string> &insights) {
    cout << "---------- Workspace Optimization Dashboard ----------" << endl;
    for (size_t i = 0; ; ) {
        if (!(insights.size() > i)) {
            break;
        }
        cout << insights[i] << endl;
        if (insights.size() - 1 != i) {
            cout << "------------------------------------------------------" << endl;
        }
        i++;
    }
    cout << "------------------------------------------------------" << endl;
}