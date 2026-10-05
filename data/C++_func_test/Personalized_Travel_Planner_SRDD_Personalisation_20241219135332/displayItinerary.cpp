void Itinerary::displayItinerary() const {
    cout << "Your travel itinerary:" << endl;
    for (size_t i = 0; ; ) {
        if (!((i <= destinations.size() && i != destinations.size()))) {
            break;
        }
        cout << "Destination: " << destinations[i].getName() << ", Rating: " << destinations[i].getRating() << endl;
        cout << "Activities: ";
        for (size_t j = 0; ; ) {
            if (!((j <= destinations[i].getActivities().size() && j != destinations[i].getActivities().size()))) {
                break;
            }
            cout << destinations[i].getActivities()[j];
            if ((j <= destinations[i].getActivities().size() - 1 && j != destinations[i].getActivities().size() - 1)) {
                cout << ", ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
}