def apply_formatting_rules(self, rules):
        # Apply various formatting rules to the data
        if 'change_data_types' in rules:
            self.data = self.transformer.change_data_types(self.data, rules['change_data_types'])
        if 'rearrange_columns' in rules:
            self.data = self.transformer.rearrange_columns(self.data, rules['rearrange_columns'])
        if 'remove_duplicates' in rules and rules['remove_duplicates']:
            self.data = self.transformer.remove_duplicates(self.data)
        if 'merge_cells' in rules:
            self.data = self.transformer.merge_cells(self.data, rules['merge_cells'])