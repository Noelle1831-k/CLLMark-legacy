void Network::addUser(shared_ptr<User> user) {
    users.push_back(user);
    cout << "User " << user->getUsername() << " added to the network." << endl;
}