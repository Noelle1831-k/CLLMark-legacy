def check_missing_values(self):
        '''
        Checks for missing values in the dataset and generates a report.
        '''
        missing_values = self.dataset.isnull().sum()
        total_missing = missing_values.sum()
        missing_percentage = (missing_values / len(self.dataset)) * 100
        missing_values_report = missing_values[missing_values > 0]
        return (f"Missing Values Report:\n"
                f"Total Missing Values: {total_missing}\n"
                f"Missing Values Percentage:\n{missing_percentage}\n"
                f"Details:\n{missing_values_report}\n")