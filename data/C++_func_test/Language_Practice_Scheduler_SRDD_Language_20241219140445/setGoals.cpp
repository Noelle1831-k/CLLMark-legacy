void User::setGoals() {
    cout << "Enter your language learning goals (type 'done' to finish): ";
    string goal;
    while (cin >> goal && goal != "done") {
        goals.push_back(goal);
    }
}