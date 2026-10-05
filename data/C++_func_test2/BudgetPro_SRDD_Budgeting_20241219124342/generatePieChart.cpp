void Visualizer::generatePieChart(const vector<double>& data) const {
    cout << "\nGenerating Pie Chart:\n";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Category " << i + 1 << ": " << data[i] << "\n";
    }
}