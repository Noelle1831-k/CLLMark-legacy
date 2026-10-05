Event UserInterface::getEventDetails() {
    string type = getInput("Enter event type (party, conference, wedding): ");
    int guestCount = stoi(getInput("Enter guest count: "));
    double budget = stod(getInput("Enter budget: "));
    string date = getInput("Enter preferred date: ");
    string venue = getInput("Enter venue: ");
    vector<string> preferences;
    preferences.push_back(getInput("Enter any specific preferences: "));
    return Event(type, guestCount, budget, date, venue, preferences);
}