void Application::createRequest() {
    string type, user;
    cout << "Enter request type: ";
    cin >> type;
    cout << "Enter user name: ";
    cin >> user;
    Request request(type, user);
    db.addRequest(request);
}