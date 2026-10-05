def main():
    analyzer = CoverageAnalyzer('source_code.py', 'test_code.py')
    analyzer.analyze_coverage()
    analyzer.display_results()