void Visualizer::displayBarChart(const vector<Transaction> &transactions) {
    cout << "\n=== Bar Chart Visualization ===\n";
    for (const auto &transaction : transactions) {
        cout << setw(10) << transaction.getDescription() << " | ";
        int barLength = static_cast<int>(transaction.getAmount() / 10);
        for (int i = 0; i < barLength; ++i) {
            cout << "=";
        }
        cout << " " << transaction.getAmount() << "\n";
    }
}