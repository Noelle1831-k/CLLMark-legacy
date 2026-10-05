def select_columns(self, dataframe, columns):
        '''
        Selects specific columns from the dataset.
        Args:
            dataframe (pd.DataFrame): The dataset.
            columns (list): List of columns to select.
        Returns:
            pd.DataFrame: A DataFrame containing only the selected columns.
        '''
        return dataframe[columns]