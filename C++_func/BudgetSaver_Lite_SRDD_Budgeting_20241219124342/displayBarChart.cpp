void Visualizer::displayBarChart(const map<string, double>& data) {
    cout << "\nBar Chart Representation:" << endl;
    for (map<string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
        cout << it->first << ": ";
        int bars = static_cast<int>(it->second / 10);
        for (int i = 0; i < bars; ++i) {
            cout << "|";
        }
        cout << " $" << fixed << setprecision(2) << it->second << endl;
    }
}