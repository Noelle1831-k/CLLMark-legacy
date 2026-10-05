void FinancialGoal::displayGoal() const {
    cout << "Goal: " << goalName << endl;
    cout << "Target: $" << targetAmount << ", Current: $" << currentAmount << endl;
    cout << "Progress: " << fixed << setprecision(2) << getProgress() << "%" << endl;
    cout << "Milestones: ";
    for (size_t i = 0; i < milestones.size(); i++) {
        cout << milestones[i] << " ";
    }
    cout << endl;
}