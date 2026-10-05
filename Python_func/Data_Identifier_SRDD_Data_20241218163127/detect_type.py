def detect_type(self, column):
        '''
        Detect the type of a single attribute.
        '''
        # Filter out empty values
        non_empty_values = [value for value in column if value.strip()]
        if not non_empty_values:
            return "Unknown"  # or another appropriate type for empty columns
        if all(self.data_type.is_integer(value) for value in non_empty_values):
            return "Integer"
        elif all(self.data_type.is_float(value) for value in non_empty_values):
            return "Float"
        elif all(self.data_type.is_date(value) for value in non_empty_values):
            return "Date"
        else:
            return "String"