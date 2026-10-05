def main():
    directory = "path/to/source/code"
    file_reader = FileReader()
    files = file_reader.read_files(directory)
    code_analyzer = CodeAnalyzer()
    code_segments = code_analyzer.analyze_code(files)
    duplicate_detector = DuplicateDetector()
    duplicates = duplicate_detector.detect_duplicates(code_segments)
    report_generator = ReportGenerator()
    report_generator.generate_report(duplicates)
    visualizer = Visualizer()
    visualizer.visualize(duplicates)