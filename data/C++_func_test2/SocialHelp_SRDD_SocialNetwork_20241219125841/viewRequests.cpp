void Application::viewRequests() {
    vector<Request> requests = db.getRequests();
    for (const Request& request : requests) {
        cout << "Request: " << request.getType() << " by " << request.getUser() << "\n";
    }
}