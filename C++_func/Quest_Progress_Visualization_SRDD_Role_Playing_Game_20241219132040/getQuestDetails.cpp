void UI::getQuestDetails(string &name, vector<string> &objectives, string &reward) {
    cout << "Enter quest name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter number of objectives: ";
    int numObjectives;
    cin >> numObjectives;
    cin.ignore();
    for (int i = 0; i < numObjectives; i++) {
        string objective;
        cout << "Enter objective " << i + 1 << ": ";
        getline(cin, objective);
        objectives.push_back(objective);
    }
    cout << "Enter reward: ";
    getline(cin, reward);
}