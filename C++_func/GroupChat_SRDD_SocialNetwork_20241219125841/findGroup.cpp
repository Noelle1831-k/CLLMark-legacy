Group* GroupChatApp::findGroup(const string& groupName) {
    for (size_t i = 0; i < groups.size(); ++i) {
        if (groups[i]->getGroupName() == groupName) return groups[i];
    }
    return nullptr;
}