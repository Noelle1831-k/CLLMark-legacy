def convert(self, data, columns, rows, data_types):
        data = self.filter_data(data, columns, rows)
        data = self.change_data_types(data, data_types)
        return data