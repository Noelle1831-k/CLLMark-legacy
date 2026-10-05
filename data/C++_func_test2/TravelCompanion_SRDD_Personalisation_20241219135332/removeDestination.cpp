void Itinerary::removeDestination(const string& name) {
    destinations.erase(remove_if(destinations.begin(), destinations.end(), [&](const Destination& d) { return d.getLocation() == name; }), destinations.end());
}