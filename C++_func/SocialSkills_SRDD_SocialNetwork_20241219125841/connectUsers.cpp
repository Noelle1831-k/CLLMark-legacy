void Community::connectUsers() {
    cout << "Connecting to the community..." << endl;
    users.push_back("User1");
    users.push_back("User2");
    users.push_back("User3");
    cout << "Users in the community: ";
    for (unsigned int i = 0; i < users.size(); i++) {
        cout << users[i] << (i == users.size() - 1 ? "" : ", ");
    }
    cout << endl;
}