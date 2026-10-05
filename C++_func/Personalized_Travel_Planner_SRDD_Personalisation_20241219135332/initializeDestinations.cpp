void TravelPlanner::initializeDestinations() {
    Destination dest1("Beach Paradise", 4.5);
    dest1.addActivity("beach");
    dest1.addActivity("snorkeling");
    allDestinations.push_back(dest1);
    Destination dest2("Cultural City", 4.7);
    dest2.addActivity("museum");
    dest2.addActivity("art gallery");
    allDestinations.push_back(dest2);
    Destination dest3("Mountain Retreat", 4.8);
    dest3.addActivity("hiking");
    dest3.addActivity("camping");
    allDestinations.push_back(dest3);
}