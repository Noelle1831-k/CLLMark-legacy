Poll Poll::createPoll(const User& creator, const string& title, const vector<string>& options, int duration) {
    cout << "Poll created by user: " << creator.getUsername() << endl;
    return Poll(title, options, duration);
}