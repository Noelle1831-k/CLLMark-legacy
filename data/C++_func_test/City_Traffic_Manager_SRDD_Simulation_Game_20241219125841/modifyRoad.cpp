void City::modifyRoad() {
    string name;
    int length, lanes;
    cout << "Enter road name to modify: ";
    cin >> name;
    cout << "Enter new length and lanes: ";
    cin >> length >> lanes;
    for (int i = 0; i < roads.size(); i++) {
        if (roads[i].getName() == name) {
            roads[i].setLength(length);
            roads[i].setLanes(lanes);
            cout << "Road modified successfully." << endl;
            return;
        }
    }
    cout << "Road not found." << endl;
}