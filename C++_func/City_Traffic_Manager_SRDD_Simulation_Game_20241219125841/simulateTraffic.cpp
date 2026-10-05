void City::simulateTraffic() {
    for (int i = 0; i < roads.size(); i++) {
        roads[i].calculateTrafficFlow();
    }
    for (int i = 0; i < trafficSignals.size(); i++) {
        trafficSignals[i].optimizeSignal();
    }
    for (int i = 0; i < publicTransports.size(); i++) {
        publicTransports[i].optimizeSchedule();
    }
}