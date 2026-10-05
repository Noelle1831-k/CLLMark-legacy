void Visualization::generatePieChart(const map<string, double> &categoryTotals) const {
    cout << "Pie Chart Representation:" << endl;
    for (map<string, double>::const_iterator it = categoryTotals.begin(); it != categoryTotals.end(); ++it) {
        cout << it->first << ": " << fixed << setprecision(2) << it->second << "%" << endl;
    }
}