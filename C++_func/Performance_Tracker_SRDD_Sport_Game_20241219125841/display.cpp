void Dashboard::display(const vector<Athlete>& athletes) const {
    if (athletes.empty()) {
        cout << "No athletes available to display.\n";
        return;
    }
    cout << "Athlete Performance Dashboard:\n";
    for (size_t i = 0; i < athletes.size(); i++) {
        cout << "Name: " << athletes[i].getName() << "\n";
        cout << "Speed: " << athletes[i].getMetrics().getSpeed() << "\n";
        cout << "Agility: " << athletes[i].getMetrics().getAgility() << "\n";
        cout << "Accuracy: " << athletes[i].getMetrics().getAccuracy() << "\n";
        cout << "--------------------------\n";
    }
}