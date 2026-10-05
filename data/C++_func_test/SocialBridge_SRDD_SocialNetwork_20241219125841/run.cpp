void Platform::run() {
    cout << "Running the platform..." << endl;
    User* user1 = new User("Alice", "alice@example.com", "Student");
    Professional* prof1 = new Professional("Bob", "bob@example.com");
    users.push_back(user1);
    professionals.push_back(prof1);
    user1->createProfile();
    vector<string> pros = user1->searchProfessionals(), msgs = messaging.receiveMessages(), res = resource.accessResources();
    MentorshipRequest request("Alice", "Bob");
    request.sendRequest();
    prof1->acceptRequest();
    messaging.sendMessage("Hello, Bob!");

    resource.addResource("Resume Writing Guide");

    careerFair.registerUser("Alice");
    careerFair.hostEvent();
}