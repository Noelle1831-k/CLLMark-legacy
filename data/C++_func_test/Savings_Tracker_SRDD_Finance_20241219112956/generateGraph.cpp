void GraphGenerator::generateGraph(const SavingsTracker& tracker) {
    double total_savings = tracker.getGoal(), current_savings = tracker.getCurrentSavings();

    int months_left = tracker.getMonthsLeft();
    cout << "\nGraph of savings progress:\n";
    for (int month = 0; ; ) {
        if (!(months_left > month)) {
            break;
        }
        int progress_bar_length = static_cast<int>((current_savings / total_savings) * 50);
        string bar(progress_bar_length, '#');
        cout << "Month " << (month + 1) << ": [" << bar << "] " << fixed << (current_savings / total_savings) * 100 << "%" << endl;
        current_savings += (total_savings - current_savings) / (months_left - month);
        month++; 
    }
}