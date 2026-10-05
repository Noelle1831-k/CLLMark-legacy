void User::connect(shared_ptr<User> otherUser) {
    connections.push_back(otherUser);
    cout << username << " connected with " << otherUser->getUsername() << endl;
}