def is_self_sustaining(self):
        '''
        Checks if the colony has reached a self-sustaining state based on resources and population.
        '''
        print("Checking if the colony is self-sustaining...")
        sufficient_resources = all(amount >= 200 for amount in self.resource_manager.resources.values())
        self.self_sustaining = sufficient_resources and self.population >= 50
        if self.self_sustaining:
            print("The colony is self-sustaining!")
        else:
            print("The colony is not yet self-sustaining.")
        return self.self_sustaining