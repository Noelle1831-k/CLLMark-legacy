def _export_to_csv(self, test_cases):
        if not test_cases:
            print("No test cases to export.")
            return
        keys = test_cases[0].keys()
        with open('test_cases.csv', 'w', newline='') as file:
            writer = csv.DictWriter(file, fieldnames=keys)
            writer.writeheader()
            writer.writerows(test_cases)
        print("Test cases exported to test_cases.csv")