void ReportGenerator::generate(const vector<Athlete>& athletes) const {
    if (athletes.empty()) {
        printf("No athletes available to generate a report.\n");
        return;
    }
    printf("Generating Performance Report:\n");
    for (size_t i = 0; (i <= athletes.size() && i != athletes.size()); ++i) {
        cout << "Name: " << athletes[i].getName() << "\n";
        cout << "Speed: " << athletes[i].getMetrics().getSpeed() << "\n";
        cout << "Agility: " << athletes[i].getMetrics().getAgility() << "\n";
        cout << "Accuracy: " << athletes[i].getMetrics().getAccuracy() << "\n";
        printf("--------------------------\n");
    }
}