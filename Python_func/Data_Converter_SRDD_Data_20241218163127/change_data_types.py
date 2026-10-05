def change_data_types(self, data, data_types):
        for column, dtype in data_types.items():
            data[column] = data[column].astype(dtype)
        return data