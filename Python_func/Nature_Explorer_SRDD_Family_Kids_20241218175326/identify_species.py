def identify_species(self):
        '''
        Identifies a species based on input data.
        '''
        name = input("Enter the name of the species: ")
        if name in self.species_data:
            print(f"Species identified: {self.species_data[name]}")
        else:
            print("Species not found. Would you like to add it to the database? (yes/no)")
            choice = input().lower()
            if choice == 'yes':
                self.add_species(name)