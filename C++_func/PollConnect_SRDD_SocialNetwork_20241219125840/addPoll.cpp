void PollManager::addPoll(const Poll& poll) {
    polls.push_back(poll);
    cout << "Poll added with ID: " << poll.getId() << endl;
}