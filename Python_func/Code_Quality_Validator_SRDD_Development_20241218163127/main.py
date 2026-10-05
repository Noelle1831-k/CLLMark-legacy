def main():
    if len(sys.argv) != 2:
        print("Usage: python main.py <source_code_file>")
        return
    file_path = sys.argv[1]
    source_code = read_file(file_path)
    if not source_code:
        print("No source code to analyze.")
        return
    parser = CodeParser(source_code)
    ast = parser.parse()
    if ast is None:
        print("Parsing failed due to syntax errors.")
        return
    analyzer = CodeAnalyzer(ast)
    issues = analyzer.analyze()
    report_generator = ReportGenerator(issues)
    report = report_generator.generate_report()
    write_report(report, "analysis_report.txt")
    print("Analysis complete. Report saved to analysis_report.txt.")