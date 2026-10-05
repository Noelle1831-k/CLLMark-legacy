void SavingsTracker::displayProgress() const {
    double percentage_complete = (current_savings / savings_goal) * 100;
    cout << "\nProgress for " << user_name << ":" << endl;
    cout << "Goal: $" << savings_goal << endl;
    cout << "Current savings: $" << fixed << setprecision(2) << current_savings << endl;
    cout << "Progress: " << percentage_complete << "%" << endl;
}