def execute(self):
        execution_results = {}
        for test_case in self.test_cases:
            test_case.run()
            execution_results[test_case.name] = test_case.get_result()
        self.execution_history.append({
            'timestamp': datetime.datetime.now().isoformat(),
            'results': execution_results
        })