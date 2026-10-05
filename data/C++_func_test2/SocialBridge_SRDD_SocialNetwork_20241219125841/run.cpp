void Platform::run() {
    cout << "Running the platform..." << endl;
    User* user1 = new User("Alice", "alice@example.com", "Student");
    Professional* prof1 = new Professional("Bob", "bob@example.com");
    users.push_back(user1);
    professionals.push_back(prof1);
    user1->createProfile();
    vector<string> pros = user1->searchProfessionals();
    MentorshipRequest request("Alice", "Bob");
    request.sendRequest();
    prof1->acceptRequest();
    messaging.sendMessage("Hello, Bob!");
    vector<string> msgs = messaging.receiveMessages();
    resource.addResource("Resume Writing Guide");
    vector<string> res = resource.accessResources();
    careerFair.registerUser("Alice");
    careerFair.hostEvent();
}