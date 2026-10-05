def validate_data(self, data):
        if data is None:
            return False
        if data.empty:
            return False
        if not all(isinstance(col, str) for col in data.columns):
            return False
        return True