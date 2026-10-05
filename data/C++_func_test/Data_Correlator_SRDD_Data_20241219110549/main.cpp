int main() {
    Dataset dataset;
    CorrelationCalculator calculator;
    Visualization visualizer;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string filename;
                cout << "Enter dataset file path: ";
                cin >> filename;
                if (dataset.loadDataset(filename)) {
                    cout << "Dataset successfully loaded.\n";
                } else {
                    cout << "Failed to load dataset.\n";
                }
                break;
            }
            case 2: {
                vector<string> variables = dataset.getVariableNames();
                if (variables.empty()) {
                    cout << "No variables found. Please import a dataset first.\n";
                    break;
                }
                cout << "Available Variables:\n";
                for (size_t i = 0; i < variables.size(); ++i) {
                    cout << i + 1 << ". " << variables[i] << "\n";
                }
                cout << "Enter indices of two variables to analyze (e.g., 1 2): ";
                int var1, var2;
                cin >> var1 >> var2;
                if (var1 > 0 && var1 <= variables.size() && var2 > 0 && var2 <= variables.size()) {
                    double pearson = calculator.calculatePearson(dataset, var1 - 1, var2 - 1);
                    double spearman = calculator.calculateSpearman(dataset, var1 - 1, var2 - 1);
                    cout << "Pearson Correlation: " << pearson << "\n";
                    cout << "Spearman Correlation: " << spearman << "\n";
                } else {
                    cout << "Invalid indices.\n";
                }
                break;
            }
            case 3: {
                cout << "Generating visualization...\n";
                visualizer.generateScatterPlot(dataset);
                visualizer.generateCorrelationMatrix(dataset, calculator);
                break;
            }
            case 4:
                cout << "Exiting application. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}