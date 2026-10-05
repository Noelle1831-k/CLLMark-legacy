Poll* PollManager::findPollById(int id) {
    for (auto& poll : polls) {
        if (poll.getId() == id) {
            return &poll;
        }
    }
    return nullptr;
}