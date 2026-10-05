def group_rows(self, data, columns):
        # Group rows by specified columns
        return data.groupby(columns)