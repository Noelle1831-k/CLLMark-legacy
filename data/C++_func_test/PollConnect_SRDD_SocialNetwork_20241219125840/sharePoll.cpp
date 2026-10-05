void Network::sharePoll(const Poll& poll, const User& user) {
    cout << "Poll \"" << poll.getTitle() << "\" shared with user: " << user.getUsername() << endl;
}