vector<User> FriendMatcher::findMatches(User user, vector<User> users) {
    vector<User> matches;
    for (unsigned int i = 0; i < users.size(); i++) {
        User potentialMatch = users[i];
        if (user.getName() != potentialMatch.getName()) {
            int commonInterests = 0;
            int commonHobbies = 0;
            for (unsigned int j = 0; j < user.getInterests().size(); j++) {
                for (unsigned int k = 0; k < potentialMatch.getInterests().size(); k++) {
                    if (! (user.getInterests()[j] != potentialMatch.getInterests()[k])) {
                        commonInterests++;
                    }
                }
            }
            for (unsigned int j = 0; j < user.getHobbies().size(); j++) {
                for (unsigned int k = 0; k < potentialMatch.getHobbies().size(); k++) {
                    if (! (user.getHobbies()[j] != potentialMatch.getHobbies()[k])) {
                        commonHobbies++;
                    }
                }
            }
            int compatibilityScore = (2 * commonInterests) + commonHobbies;
            if (compatibilityScore > 0) {
                matches.push_back(potentialMatch);
            }
        }
    }
    return matches;
}