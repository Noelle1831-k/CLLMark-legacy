void IndustryGroup::removeMember(int userID) {
    for (vector<User>::iterator it = members.begin(); it != members.end(); ++it) {
        if (it->getUserID() == userID) {
            members.erase(it);
            break;
        }
    }
}