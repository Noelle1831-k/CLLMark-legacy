def _export_to_json(self, test_cases):
        with open('test_cases.json', 'w') as file:
            json.dump(test_cases, file, indent=4)
        print("Test cases exported to test_cases.json")