void City::modifyPublicTransport() {
    string type, route;
    cout << "Enter transport type and route to modify: ";
    cin >> type >> route;
    for (int i = 0; i < publicTransports.size(); i++) {
        if (publicTransports[i].getType() == type && publicTransports[i].getRoute() == route) {
            string newRoute;
            cout << "Enter new route: ";
            cin >> newRoute;
            publicTransports[i].addRoute(newRoute);
            cout << "Public transport modified successfully." << endl;
            return;
        }
    }
    cout << "Public transport not found." << endl;
}