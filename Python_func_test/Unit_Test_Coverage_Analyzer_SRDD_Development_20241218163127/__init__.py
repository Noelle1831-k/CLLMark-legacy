def __init__(self, source_path, test_path):
        self.source_path = source_path
        self.test_path = test_path
        self.parser = code_parser.CodeParser()
        self.calculator = coverage_calculator.CoverageCalculator()
        self.reporter = report_generator.ReportGenerator()