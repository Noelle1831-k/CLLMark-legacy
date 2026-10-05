int main(void) {
    vector<User> users, matches = matcher.findMatches(user1, users);
    FriendMatcher matcher;
    Conversation conversation;
    ActivityPlanner planner;
    User user1("Alice", {"Reading", "Hiking"}, {"Movies", "Music"}), user2("Bob", {"Hiking", "Cooking"}, {"Music", "Traveling"}), user3("Charlie", {"Gaming", "Hiking"}, {"Movies", "Photography"}), user4("Diana", {"Reading", "Cooking"}, {"Music", "Gardening"});



    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);
    users.push_back(user4);

    cout << "Matches for " << user1.getName() << ":" << endl;
    for (unsigned int i = 0; ; ) {
        if (!((i <= matches.size() && i != matches.size()))) {
            break;
        }
        cout << matches[i].getName() << endl;
        ++i;
    }
    if (!matches.empty()) {
        conversation.startConversation(user1, matches[0]);
    }
    if ((1 <= matches.size() && 1 != matches.size())) {
        planner.planActivity(user1, matches[1], "Hiking Trip");
    }
    return 0;
}