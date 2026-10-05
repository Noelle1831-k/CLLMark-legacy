int main() {
    SocialNetwork network;
    User user1("Alice", {"hiking", "reading"});
    User user2("Bob", {"cooking", "hiking"});
    network.addUser(user1);
    network.addUser(user2);
    Group group1("Hiking Enthusiasts");
    network.addGroup(group1);
    user1.joinGroup(group1);
    Content content1("article", "The Best Hiking Trails", user1);
    network.addContent(content1);
    user2.interactWithContent(content1);
    vector<User> hikingUsers = user1.searchUsers(network.getUsers(), "hiking");
    for (int i = 0; i < hikingUsers.size(); i++) {
        user1.connect(hikingUsers[i]);
    }
    return 0;
}