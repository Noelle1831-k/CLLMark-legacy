void SavingsTracker::trackSavings() {
    double monthly_savings = (savings_goal - current_savings) / months_left;
    for (int month = 1; month <= months_left; month++) {
        current_savings += monthly_savings;
        savings_history.push_back(current_savings);
    }
}