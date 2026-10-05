void Visualizer::displayPieChart(const map<string, double>& data) {
    cout << "\nPie Chart Representation:" << endl;
    double total = 0;
    for (map<string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
        total += it->second;
    }
    for (map<string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
        cout << it->first << ": " << fixed << setprecision(2) << (it->second / total) * 100 << "%" << endl;
    }
}