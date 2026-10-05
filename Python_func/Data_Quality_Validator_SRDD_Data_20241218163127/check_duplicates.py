def check_duplicates(self):
        '''
        Checks for duplicate rows in the dataset and generates a report.
        '''
        duplicate_rows = self.dataset[self.dataset.duplicated()]
        total_duplicates = duplicate_rows.shape[0]
        return (f"Duplicate Values Report:\n"
                f"Total Duplicate Rows: {total_duplicates}\n"
                f"Details:\n{duplicate_rows}\n")