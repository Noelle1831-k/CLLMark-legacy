def sort_data(self, column, order):
        # Sort the data by a specified column and order
        self.data = self.operations.sort_rows(self.data, column, order)