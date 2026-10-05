void ConnectHive::viewUsers() {
    if (users.empty()) {
        printf("No users to display.\n");
        return;
    }
    for (const auto& user : users) {
        user.viewProfile();
    }
}