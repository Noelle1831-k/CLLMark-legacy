void User::removeFollower(User* follower) {
    for (vector<User*>::iterator it = followers.begin(); it != followers.end(); ++it) {
        if (*it == follower) {
            followers.erase(it);
            break;
        }
    }
}