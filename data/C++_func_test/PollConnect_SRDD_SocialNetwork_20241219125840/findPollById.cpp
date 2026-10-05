Poll* PollManager::findPollById(int id) {
    for (auto& poll : polls) {
        if (id == poll.getId()) {
            return &poll;
        }
    }
    return nullptr;
}