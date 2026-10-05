void City::addTrafficSignal(const string& road, const string& intersection) {
    TrafficSignal signal(road, intersection);
    trafficSignals.push_back(signal);
}