void City::addRoad(const string& name, int length, int lanes) {
    Road road(name, length, lanes);
    roads.push_back(road);
}