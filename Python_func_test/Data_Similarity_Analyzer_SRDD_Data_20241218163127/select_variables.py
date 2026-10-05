def select_variables(self, data, variables):
        '''
        Select specific variables/fields from the dataset.
        '''
        try:
            selected_data = data[variables]
            return selected_data
        except KeyError as e:
            print(f"Error selecting variables: {e}")
            return None