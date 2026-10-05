def group_data(self, columns):
        # Group the data by specified columns
        self.grouped_data = self.data.groupby(columns)