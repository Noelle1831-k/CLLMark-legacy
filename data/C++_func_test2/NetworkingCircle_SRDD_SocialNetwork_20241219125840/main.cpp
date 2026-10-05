int main() {
    Network network;
    User user1(1, "Alice", "Software");
    User user2(2, "Bob", "Software");
    User user3(3, "Charlie", "Marketing");
    User user4(4, "Diana", "Software");
    network.addUser(user1);
    network.addUser(user2);
    network.addUser(user3);
    network.addUser(user4);
    network.connectUsers(1, 2);
    network.connectUsers(2, 3);
    network.connectUsers(1, 4);
    IndustryGroup softwareGroup("Software");
    softwareGroup.addMember(user1);
    softwareGroup.addMember(user2);
    softwareGroup.addMember(user4);
    cout << "Software Group Members:" << endl;
    vector<User> members = softwareGroup.getMembers();
    for (int i = 0; i < members.size(); i++) {
        cout << members[i].getName() << " (" << members[i].getIndustry() << ")" << endl;
    }
    network.removeUser(3);
    cout << "Remaining Users in the Network:" << endl;
    vector<User> remainingUsers = network.getAllUsers();
    for (int i = 0; i < remainingUsers.size(); i++) {
        cout << remainingUsers[i].getName() << " (" << remainingUsers[i].getIndustry() << ")" << endl;
    }
    return 0;
}