void Connection::establishConnection() {
    user1->connect(user2);
    user2->connect(user1);
    cout << "Connection established between " << user1->getUsername() << " and " << user2->getUsername() << endl;
}