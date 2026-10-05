int MatchmakingAlgorithm::matchUsers(const UserProfile &user1, const UserProfile &user2) {
    int score = 0;
    vector<string> skills1 = user1.getSkills();
    vector<string> skills2 = user2.getSkills();
    vector<string> interests1 = user1.getInterests();
    vector<string> interests2 = user2.getInterests();
    for (size_t i = 0; i < skills1.size(); i++) {
        for (size_t j = 0; j < skills2.size(); j++) {
            if (skills1[i] == skills2[j]) {
                score += 5; 
            }
        }
    }
    for (size_t i = 0; i < interests1.size(); i++) {
        for (size_t j = 0; j < interests2.size(); j++) {
            if (interests1[i] == interests2[j]) {
                score += 3; 
            }
        }
    }
    return score;
}