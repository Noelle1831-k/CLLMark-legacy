void PollManager::displayPolls() const {
    if (polls.empty()) {
        cout << "No polls available.\n";
        return;
    }
    cout << "Available Polls:\n";
    for (const auto& poll : polls) {
        cout << "ID: " << poll.getId() << " | Title: " << poll.getTitle() << endl;
    }
}