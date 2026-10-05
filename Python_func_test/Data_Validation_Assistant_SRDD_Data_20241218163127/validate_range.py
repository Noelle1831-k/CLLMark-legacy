def validate_range(self, data, rules):
        errors = {}
        for column, (min_val, max_val) in rules.items():
            if column in data.columns:
                if not data[column].between(min_val, max_val).all():
                    errors[column] = f"Values out of range: expected between {min_val} and {max_val}"
        return errors