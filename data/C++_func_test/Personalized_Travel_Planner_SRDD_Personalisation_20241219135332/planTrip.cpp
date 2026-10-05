void TravelPlanner::planTrip() {
    initializeDestinations();
    vector<string> prefs;
    string input;
    cout << "Enter your preferences (type 'done' when finished):" << endl;
    while (true) {
        cin >> input;
        if (input == "done") break;
        prefs.push_back(input);
    }
    userPrefs.setPreferences(prefs);
    itinerary.generateItinerary(userPrefs, allDestinations);
    itinerary.displayItinerary();
}