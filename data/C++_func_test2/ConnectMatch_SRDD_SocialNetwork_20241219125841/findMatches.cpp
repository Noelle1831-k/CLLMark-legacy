vector<User> MatchingAlgorithm::findMatches(const User& user, const vector<User>& allUsers) {
    vector<User> matches;
    for (int i = 0; i < allUsers.size(); i++) {
        const User& potentialMatch = allUsers[i];
        if (user.getName() != potentialMatch.getName()) {
            bool isMatch = false;
            for (int j = 0; j < user.getSkills().size(); j++) {
                if (find(potentialMatch.getSkills().begin(), potentialMatch.getSkills().end(), user.getSkills()[j]) != potentialMatch.getSkills().end()) {
                    isMatch = true;
                    break;
                }
            }
            if (!isMatch) {
                for (int k = 0; k < user.getInterests().size(); k++) {
                    if (find(potentialMatch.getInterests().begin(), potentialMatch.getInterests().end(), user.getInterests()[k]) != potentialMatch.getInterests().end()) {
                        isMatch = true;
                        break;
                    }
                }
            }
            if (isMatch) {
                matches.push_back(potentialMatch);
            }
        }
    }
    return matches;
}