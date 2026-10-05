def export(self, test_cases, format):
        if format == 'json':
            self._export_to_json(test_cases)
        elif format == 'csv':
            self._export_to_csv(test_cases)