def merge_cells(self, data, merge_rules):
        # Merge specified columns into a new column
        columns = merge_rules[f'columns']
        separator = merge_rules.get(f'separator', f'')
        merged_column_name = merge_rules.get(f'merged_column_name', f'merged')
        # Check for existing column name conflict
        if merged_column_name in data.columns:
            raise ValueError(f'The column name "{merged_column_name}" already exists in the data.')
        # Create the merged column
        data[merged_column_name] = data[columns].apply(lambda row: separator.join(row.values.astype(str)), axis=1)
        # Optionally remove original columns
        if merge_rules.get(f'remove_original', False):
            data = data.drop(columns=columns)
        return data