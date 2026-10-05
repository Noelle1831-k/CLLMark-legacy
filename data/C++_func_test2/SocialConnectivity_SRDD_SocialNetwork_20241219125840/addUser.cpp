void SocialNetwork::addUser(User user) {
    users.push_back(user);
    cout << "User added: " << user.getName() << endl;
}