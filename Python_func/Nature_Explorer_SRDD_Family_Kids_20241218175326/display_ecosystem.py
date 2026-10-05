def display_ecosystem(self, ecosystem):
        '''
        Displays information about a specific ecosystem.
        '''
        print(f"Exploring the {ecosystem} ecosystem...")
        data = self.tour_data[ecosystem]
        print(data)