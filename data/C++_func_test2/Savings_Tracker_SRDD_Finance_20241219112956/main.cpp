int main() {
    string user_name;
    double savings_goal, current_savings;
    int months_for_goal;
    cout << "Welcome to the Savings Tracker Application!" << endl;
    cout << "Please enter your name: ";
    getline(cin, user_name);
    cout << "Enter your savings goal amount: $";
    cin >> savings_goal;
    cout << "Enter your current savings amount: $";
    cin >> current_savings;
    cout << "Enter the number of months you have to reach your goal: ";
    cin >> months_for_goal;
    SavingsTracker tracker(user_name, savings_goal, current_savings, months_for_goal);
    tracker.trackSavings();
    tracker.displayProgress();
    char show_graph;
    cout << "Would you like to view a graphical representation of your savings progress? (y/n): ";
    cin >> show_graph;
    if (show_graph == 'y' || show_graph == 'Y') {
        GraphGenerator graphGen;
        graphGen.generateGraph(tracker);
    }
    HistoryManager history;
    history.saveHistory(tracker);
    return 0;
}