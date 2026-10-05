def main():
    file_path = 'example_code.py'
    analyzer = CodeAnalyzer()
    analyzer.load_code(file_path)
    issues = analyzer.analyze()
    for issue in issues:
        print(issue)