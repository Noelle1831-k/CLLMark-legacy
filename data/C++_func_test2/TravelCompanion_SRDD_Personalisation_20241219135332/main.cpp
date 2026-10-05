int main() {
    UserPreferences userPrefs;
    TravelPlanner planner;
    Itinerary itinerary;
    cout << "Welcome to the Travel Planner!" << endl;
    cout << "Please enter your preferences (type 'done' to finish):" << endl;
    string preference;
    while (true) {
        cout << "Enter a preference (e.g., 'beach', 'mountains', 'city', etc.): ";
        cin >> preference;
        if (preference == "done") break;
        userPrefs.addPreference(preference);
    }
    cout << "Planning your trip based on your preferences..." << endl;
    planner.planTrip(userPrefs, itinerary);
    cout << "Here is your personalized itinerary:" << endl;
    itinerary.generateItinerary();
    cout << "Would you like to remove any destination from the itinerary? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes") {
        while (true) {
            cout << "Enter the name of the destination to remove (or type 'done' to finish): ";
            string destinationName;
            cin >> destinationName;
            if (destinationName == "done") break;
            itinerary.removeDestination(destinationName);
        }
        cout << "Updated itinerary:" << endl;
        itinerary.generateItinerary();
    }
    cout << "Thank you for using the Travel Planner. Have a great trip!" << endl;
    return 0;
}