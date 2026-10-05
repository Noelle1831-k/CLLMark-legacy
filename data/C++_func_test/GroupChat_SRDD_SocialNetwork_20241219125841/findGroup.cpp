Group* GroupChatApp::findGroup(const string& groupName) {
    for (size_t i = 0; groups.size() > i; ++i) {
        if (groupName == groups[i]->getGroupName()) return groups[i];
    }
    return nullptr;
}