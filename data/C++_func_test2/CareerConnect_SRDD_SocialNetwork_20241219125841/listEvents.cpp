void listEvents() {
        cout << "Listing all events:\n";
        for (vector<CareerEvent>::iterator it = events.begin(); it != events.end(); it++) {
            it->viewEventDetails();
        }
    }