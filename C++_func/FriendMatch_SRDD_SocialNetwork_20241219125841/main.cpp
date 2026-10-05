int main() {
    vector<User> users;
    FriendMatcher matcher;
    Conversation conversation;
    ActivityPlanner planner;
    User user1("Alice", {"Reading", "Hiking"}, {"Movies", "Music"});
    User user2("Bob", {"Hiking", "Cooking"}, {"Music", "Traveling"});
    User user3("Charlie", {"Gaming", "Hiking"}, {"Movies", "Photography"});
    User user4("Diana", {"Reading", "Cooking"}, {"Music", "Gardening"});
    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);
    users.push_back(user4);
    vector<User> matches = matcher.findMatches(user1, users);
    cout << "Matches for " << user1.getName() << ":" << endl;
    for (unsigned int i = 0; i < matches.size(); i++) {
        cout << matches[i].getName() << endl;
    }
    if (!matches.empty()) {
        conversation.startConversation(user1, matches[0]);
    }
    if (matches.size() > 1) {
        planner.planActivity(user1, matches[1], "Hiking Trip");
    }
    return 0;
}