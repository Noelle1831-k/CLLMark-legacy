def main():
    '''
    Entry point of the application. Handles user input and coordinates the analysis process.
    '''
    if len(sys.argv) < 2:
        print("Usage: python main.py <code_snippet_file>")
        sys.exit(1)
    code_snippet_file = sys.argv[1]
    try:
        with open(code_snippet_file, 'r') as file:
            code_snippet = file.read()
    except FileNotFoundError:
        print(f"File {code_snippet_file} not found.")
        sys.exit(1)
    parsed_code = parse_code(code_snippet)
    analyzer = CodeAnalyzer()
    optimizer = Optimizer()
    time_complexity = analyzer.analyze_time_complexity(parsed_code)
    space_complexity = analyzer.analyze_space_complexity(parsed_code)
    inefficiencies = analyzer.detect_algorithmic_inefficiencies(parsed_code)
    print(f"Time Complexity: {time_complexity}")
    print(f"Space Complexity: {space_complexity}")
    print(f"Inefficiencies: {inefficiencies}")
    optimizations = optimizer.suggest_optimizations(parsed_code)
    print("Optimization Suggestions:")
    for suggestion in optimizations:
        print(f"- {suggestion}")