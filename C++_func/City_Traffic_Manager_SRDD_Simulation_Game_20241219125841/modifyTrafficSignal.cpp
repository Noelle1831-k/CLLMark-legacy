void City::modifyTrafficSignal() {
    string road, intersection;
    cout << "Enter road and intersection to modify signal: ";
    cin >> road >> intersection;
    for (int i = 0; i < trafficSignals.size(); i++) {
        if (trafficSignals[i].getRoad() == road && trafficSignals[i].getIntersection() == intersection) {
            int green, yellow, red;
            cout << "Enter new timings for green, yellow, and red: ";
            cin >> green >> yellow >> red;
            trafficSignals[i].setTiming(green, yellow, red);
            cout << "Traffic signal modified successfully." << endl;
            return;
        }
    }
    cout << "Traffic signal not found." << endl;
}