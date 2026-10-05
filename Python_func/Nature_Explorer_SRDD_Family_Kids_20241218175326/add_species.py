def add_species(self, name):
        '''
        Adds a new species to the database.
        '''
        scientific_name = input(f"Enter the scientific name for {name}: ")
        self.species_data[name] = scientific_name
        print(f"Species {name} added to the database.")