int UI::selectObjective(Quest &quest) {
    quest.displayQuest();
    cout << "Select an objective to complete by number: ";
    int index;
    cin >> index;
    return index - 1;
}