def is_threatened(self):
        '''
        Determines if the colony is under threat based on resource levels, health, or external challenges.
        '''
        print("Checking if the colony is threatened...")
        self.threatened = any(amount < 20 for amount in self.resource_manager.resources.values()) or self.colony_health < 30
        if self.threatened:
            print("The colony is under threat!")
        else:
            print("The colony is stable.")
        return self.threatened