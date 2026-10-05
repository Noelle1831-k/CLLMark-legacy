void Party::removeMember(string name) {
    for (size_t i = 0; i < members.size(); ++i) {
        if (members[i].getName() == name) {
            members.erase(members.begin() + i);
            break;
        }
    }
}