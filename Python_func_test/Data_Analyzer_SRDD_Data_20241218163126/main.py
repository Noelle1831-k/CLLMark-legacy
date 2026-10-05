def main():
    # Initialize components
    loader = DataLoader()
    analyzer = DataAnalyzer()
    visualizer = DataVisualizer()
    dashboard = Dashboard()
    # Load data
    data = loader.load_csv('data/sample.csv')
    # Analyze data
    stats = analyzer.calculate_statistics(data)
    correlations = analyzer.find_correlations(data)
    outliers = analyzer.detect_outliers(data)
    # Visualize data
    visualizer.plot_histogram(data, 'column1')
    visualizer.plot_scatter(data, 'column1', 'column2')
    visualizer.plot_line_chart(data, 'column1')
    # Display dashboard
    dashboard.display_dashboard(stats, correlations, outliers)