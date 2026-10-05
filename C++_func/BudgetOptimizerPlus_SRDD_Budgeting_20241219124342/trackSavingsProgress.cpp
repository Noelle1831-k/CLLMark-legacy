void SavingsTracker::trackSavingsProgress() {
    cout << "Enter the amount you have saved so far: ";
    cin >> currentSavings;
    double percentage = Utility::calculatePercentage(currentSavings, savingsGoal);
    cout << "You have saved " << Utility::formatCurrency(currentSavings) << " (" << percentage << "% of your goal)." << endl;
    if (currentSavings >= savingsGoal) {
        cout << "Congratulations! You have reached your savings goal!" << endl;
    } else {
        cout << "Keep going! You are " << Utility::formatCurrency(savingsGoal - currentSavings) << " away from your goal." << endl;
    }
}