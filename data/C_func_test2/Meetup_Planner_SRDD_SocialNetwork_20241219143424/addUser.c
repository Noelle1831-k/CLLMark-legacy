void addUser(Database *db, User *user) {
    UserList *newNode = (UserList *)malloc(sizeof(UserList));
    newNode->user = user;
    newNode->next = db->users;
    db->users = newNode;
}