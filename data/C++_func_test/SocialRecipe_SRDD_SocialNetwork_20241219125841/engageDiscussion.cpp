void Community::engageDiscussion() {
    string discussion;
    cout << "Enter your discussion topic: ";
    cin.ignore();
    getline(cin, discussion);
    discussions.push_back(discussion);
    cout << "Discussion added successfully!" << endl;
}