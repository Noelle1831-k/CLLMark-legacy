def load_shared_scenario(self, filename):
        '''
        Load a shared scenario from a file.
        Parameters:
        filename (str): The name of the file to be loaded.
        Returns:
        str: The content of the scenario file.
        '''
        with open(filename, 'r') as file:
            scenario_data = file.read()
        return scenario_data