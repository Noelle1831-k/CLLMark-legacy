void Visualizer::generateCorrelationMatrix(const CorrelationAnalyzer& analyzer) {
    cout << "Generating correlation matrix..." << endl;
    vector<vector<double>> matrix = analyzer.getCorrelationMatrix();
    for (const auto& row : matrix) {
        for (double value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}