void UserInterface::displayHeadlines(const vector<string>& headlines) {
    cout << "\nLatest News Headlines:\n";
    for (int i = 0; i < (int)headlines.size(); i++) {
        cout << i + 1 << ". " << headlines[i] << endl;
    }
}