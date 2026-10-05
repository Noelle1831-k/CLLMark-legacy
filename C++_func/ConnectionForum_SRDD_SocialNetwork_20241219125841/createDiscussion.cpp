void Discussion::createDiscussion() {
    cout << "Creating a new discussion..." << endl;
    cout << "Enter discussion topic: ";
    cin.ignore();
    getline(cin, topic);
    cout << "Discussion on '" << topic << "' created successfully!" << endl;
}