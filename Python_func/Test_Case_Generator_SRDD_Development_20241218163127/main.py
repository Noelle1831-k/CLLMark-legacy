def main():
    if len(sys.argv) < 3:
        print("Usage: python main.py <input_file> <output_format>")
        sys.exit(1)
    input_file = sys.argv[1]
    output_format = sys.argv[2].lower()
    if output_format not in ['json', 'csv']:
        print("Output format must be either 'json' or 'csv'.")
        sys.exit(1)
    generator = TestCaseGenerator()
    test_cases = generator.generate_test_cases(input_file)
    exporter = Exporter()
    exporter.export(test_cases, output_format)