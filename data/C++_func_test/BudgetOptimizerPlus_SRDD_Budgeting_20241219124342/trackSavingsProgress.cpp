void SavingsTracker::trackSavingsProgress() {
    printf("Enter the amount you have saved so far: ");
    cin >> currentSavings;
    double percentage = Utility::calculatePercentage(currentSavings, savingsGoal);
    cout << "You have saved " << Utility::formatCurrency(currentSavings) << " (" << percentage << "% of your goal)." << endl;
    if (currentSavings >= savingsGoal) {
        printf("Congratulations! You have reached your savings goal!\n");
    } else {
        cout << "Keep going! You are " << Utility::formatCurrency(savingsGoal - currentSavings) << " away from your goal." << endl;
    }
}