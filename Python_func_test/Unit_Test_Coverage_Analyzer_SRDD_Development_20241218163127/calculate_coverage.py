def calculate_coverage(self, source_functions, test_functions):
        utils.log_message("Calculating coverage...")
        covered = set(source_functions) & set(test_functions)
        coverage_percentage = (len(covered) / len(source_functions)) * 100 if source_functions else 0
        utils.log_message(f"Coverage calculated: {coverage_percentage}%")
        return {'coverage': coverage_percentage, 'covered': covered}