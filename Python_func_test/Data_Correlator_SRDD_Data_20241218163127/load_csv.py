def load_csv(self, file_path):
        '''
        Loads a CSV file into a Pandas DataFrame.
        Args:
            file_path (str): The path to the CSV file.
        Returns:
            pd.DataFrame: A DataFrame containing the dataset.
        '''
        return pd.read_csv(file_path)