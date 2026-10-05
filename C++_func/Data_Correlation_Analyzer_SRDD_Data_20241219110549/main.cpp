int main() {
    Dataset dataset;
    dataset.loadData("data.csv");
    CorrelationAnalyzer analyzer;
    analyzer.calculateCorrelation(dataset);
    Visualizer visualizer;
    visualizer.generateScatterPlot(analyzer);
    visualizer.generateCorrelationMatrix(analyzer);
    return 0;
}