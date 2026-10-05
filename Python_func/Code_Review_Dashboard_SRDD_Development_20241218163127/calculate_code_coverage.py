def calculate_code_coverage(self, coverage_data):
        """Calculates average code coverage based on provided data."""
        try:
            coverage_values = [file_data["coverage"] for file_data in coverage_data if "coverage" in file_data]
            return sum(coverage_values) / len(coverage_values) if coverage_values else 0
        except Exception as e:
            raise ValueError(f"Error calculating code coverage: {e}")