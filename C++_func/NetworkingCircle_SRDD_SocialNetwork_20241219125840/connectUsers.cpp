void Network::connectUsers(int userID1, int userID2) {
    User* user1 = findUserByID(userID1);
    User* user2 = findUserByID(userID2);
    if (user1 && user2) {
        user1->addConnection(userID2);
        user2->addConnection(userID1);
    }
}