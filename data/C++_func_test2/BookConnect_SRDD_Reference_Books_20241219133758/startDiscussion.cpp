void BookClub::startDiscussion(const string &topic) {
    discussionThreads.push_back(topic);
    cout << "Discussion on '" << topic << "' started.\n";
}