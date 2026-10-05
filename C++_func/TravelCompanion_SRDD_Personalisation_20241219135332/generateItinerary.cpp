void Itinerary::generateItinerary() const {
    for (const auto& destination : destinations) {
        cout << "Destination: " << destination.getLocation() << endl;
        cout << "Activities: ";
        for (const auto& activity : destination.getActivities()) {
            cout << activity << ", ";
        }
        cout << endl;
    }
}