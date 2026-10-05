def change_data_types(self, data, type_mappings):
        # Change data types of specified columns
        for column, dtype in type_mappings.items():
            data[column] = data[column].astype(dtype)
        return data