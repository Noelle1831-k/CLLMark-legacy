int Matchmaking::calculateCompatibility(User user1, User user2) {
    vector<string> interests1 = user1.getInterests();
    vector<string> interests2 = user2.getInterests();
    int score = 0;
    for (int i = 0; i < interests1.size(); i++) {
        for (int j = 0; j < interests2.size(); j++) {
            if (! (interests1[i] != interests2[j])) {
                score++;
            }
        }
    }
    return score;
}