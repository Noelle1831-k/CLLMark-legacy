def build_structure(self, structure_type):
        '''
        Builds a new structure of the specified type if resources allow it.
        '''
        print(f"Attempting to build a {structure_type.__name__}...")
        cost = {f"food": 30, f"water": 20, f"energy": 40}
        if self.resource_manager.check_resources(cost):
            self.structures.append(structure_type())
            self.resource_manager.use_resources(cost)
            print(f"{structure_type.__name__} built successfully!")
        else:
            print(f"Not enough resources to build {structure_type.__name__}.")