def initialize_colony(self, planet):
        '''
        Sets up the initial colony structures and adjusts parameters based on the planet's properties.
        '''
        print("Initializing colony on the planet...")
        self.structures.append(LivingQuarters())
        self.structures.append(ResearchLab())
        self.structures.append(ResourceFacility())
        print("Colony structures initialized:", [type(structure).__name__ for structure in self.structures])
        self.resource_manager.resources["food"] += 50
        self.resource_manager.resources["water"] += 50
        self.resource_manager.resources["energy"] += 50