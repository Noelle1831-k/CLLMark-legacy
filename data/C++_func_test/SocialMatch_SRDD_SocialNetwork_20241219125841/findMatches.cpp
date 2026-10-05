vector<User> Matchmaking::findMatches(User user, vector<User> users) {
    vector<User> matches;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getName() != user.getName()) {
            int score = calculateCompatibility(user, users[i]);
            if (score > 0) {
                User match = users[i]; 
                match.setCompatibilityScore(score); 
                matches.push_back(match);
            }
        }
    }
    return matches;
}