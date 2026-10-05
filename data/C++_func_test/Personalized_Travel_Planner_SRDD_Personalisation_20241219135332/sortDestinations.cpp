void sortDestinations(vector<Destination>& destinations) {
    sort(destinations.begin(), destinations.end(), [](const Destination& a, const Destination& b) {
        return a.getRating() > b.getRating();
    });
}