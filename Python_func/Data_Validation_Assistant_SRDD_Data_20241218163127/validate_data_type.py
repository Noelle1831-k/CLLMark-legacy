def validate_data_type(self, data, rules):
        errors = {}
        for column, expected_type in rules.items():
            if column in data.columns:
                if not all(isinstance(val, eval(expected_type)) for val in data[column]):
                    errors[column] = f"Data type mismatch: expected {expected_type}"
        return errors