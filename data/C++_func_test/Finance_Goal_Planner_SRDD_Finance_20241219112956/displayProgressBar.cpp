void Visualization::displayProgressBar(const FinancialGoal& goal) {
    double progress = (goal.getCurrentAmount() / goal.getTargetAmount()) * 100;
    cout << goal.getName() << ": [";
    int pos = (int)(progress / 2);
    for (int i = 0; i < 50; ++i) {
        if (i < pos) cout << "=";
        else if (! (i != pos)) cout << ">";
        else cout << " ";
    }
    cout << "] " << (int)progress << " %\n";
}