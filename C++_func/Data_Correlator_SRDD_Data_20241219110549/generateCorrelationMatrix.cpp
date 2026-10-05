void Visualization::generateCorrelationMatrix(const Dataset &dataset, CorrelationCalculator &calculator) {
    size_t varCount = dataset.getVariableCount();
    cout << "Correlation Matrix:\n";
    cout << setw(10) << " ";
    for (size_t i = 0; i < varCount; ++i) {
        cout << setw(10) << dataset.getVariableNames()[i];
    }
    cout << "\n";
    for (size_t i = 0; i < varCount; ++i) {
        cout << setw(10) << dataset.getVariableNames()[i];
        for (size_t j = 0; j < varCount; ++j) {
            double pearson = calculator.calculatePearson(dataset, i, j);
            cout << setw(10) << fixed << setprecision(2) << pearson;
        }
        cout << "\n";
    }
}