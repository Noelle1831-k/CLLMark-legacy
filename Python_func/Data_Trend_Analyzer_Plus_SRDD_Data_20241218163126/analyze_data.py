def analyze_data(data):
    '''
    Perform data analysis.
    '''
    analyzer = stat_analysis.StatisticalAnalyzer()
    stats = analyzer.calculate_statistics(data)
    hypothesis_results = analyzer.perform_hypothesis_testing(data)
    return stats, hypothesis_results