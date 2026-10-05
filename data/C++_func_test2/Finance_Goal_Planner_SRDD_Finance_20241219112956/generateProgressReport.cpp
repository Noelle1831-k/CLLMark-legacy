void Visualization::generateProgressReport(const vector<FinancialGoal>& goals) {
    cout << "Progress Report:" << endl;
    vector<FinancialGoal>::const_iterator it;
    for (it = goals.begin(); it != goals.end(); ++it) {
        displayProgressBar(*it);
    }
}