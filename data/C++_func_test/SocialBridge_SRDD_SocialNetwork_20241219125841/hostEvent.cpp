void CareerFair::hostEvent() {
    cout << "Hosting career fair event..." << endl;
    for (const auto& user : registeredUsers) {
        cout << "User attending: " << user << endl;
    }
}