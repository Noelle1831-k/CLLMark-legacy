def validate_uniqueness(self, data, columns):
        errors = {}
        for column in columns:
            if column in data.columns:
                if data[column].duplicated().any():
                    errors[column] = "Duplicate values found"
        return errors