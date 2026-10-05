def sort_rows(self, data, column, order):
        # Sort rows by a specified column and order
        return data.sort_values(by=column, ascending=(order == 'asc'))