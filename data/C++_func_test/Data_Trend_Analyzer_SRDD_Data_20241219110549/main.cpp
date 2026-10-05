int main(int argc, char *argv[]) {
    DataLoader dataLoader;
    TrendAnalyzer trendAnalyzer;
    Visualization visualization;
    Dashboard dashboard;
    dataLoader.loadData("data.csv");
    trendAnalyzer.calculateTrends(dataLoader.getData());
    visualization.plotTrends(trendAnalyzer.getTrends());
    dashboard.displayDashboard();
    return 0;
}