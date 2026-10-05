void Itinerary::displayItinerary() const {
    cout << "Your travel itinerary:" << endl;
    for (size_t i = 0; i < destinations.size(); i++) {
        cout << "Destination: " << destinations[i].getName() << ", Rating: " << destinations[i].getRating() << endl;
        cout << "Activities: ";
        for (size_t j = 0; j < destinations[i].getActivities().size(); j++) {
            cout << destinations[i].getActivities()[j];
            if (j < destinations[i].getActivities().size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}