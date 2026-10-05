int UI::selectQuest(vector<Quest> &quests) {
    cout << "Select a quest by number: ";
    int index;
    cin >> index;
    return index - 1;
}