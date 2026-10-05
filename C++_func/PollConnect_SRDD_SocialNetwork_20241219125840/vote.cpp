void Poll::vote(const User& user, int optionId) {
    if (optionId < 0 || optionId >= options.size()) {
        cout << "Invalid option.\n";
        return;
    }
    if (voters[user.getId()]) {
        cout << "User has already voted.\n";
        return;
    }
    votes[optionId]++;
    voters[user.getId()] = true;
    cout << "Vote recorded for option: " << options[optionId] << endl;
}