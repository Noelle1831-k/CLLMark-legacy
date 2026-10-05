void listEvents() {
        cout << "Listing all events:\n";
        for (vector<CareerEvent>::iterator it = events.begin(); events.end() != it; it++) {
            it->viewEventDetails();
        }
    }