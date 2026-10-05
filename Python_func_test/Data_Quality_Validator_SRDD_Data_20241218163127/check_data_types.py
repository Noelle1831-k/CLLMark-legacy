def check_data_types(self):
        '''
        Validates the data types of all columns in the dataset and generates a report.
        '''
        data_types = self.dataset.dtypes
        non_standard_types = data_types[~data_types.isin(["int64", "float64", "object"])]
        return ("Data Types Report:\n"
                f"All Column Data Types:\n{data_types}\n"
                f"Non-Standard Types:\n{non_standard_types}\n")