void Group::listMessages() const {
    cout << "Messages in " << groupName << ":" << endl;
    for (size_t i = 0; i < messages.size(); ++i) {
        cout << messages[i].getContent() << endl;
    }
}