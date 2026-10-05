def manage_resources(self):
        '''
        Allocates and tracks resources while maintaining the colony's health and population.
        '''
        print("Managing resources...")
        self.resource_manager.allocate_resources()
        self.resource_manager.track_resources()
        # Adjust colony health based on resource availability
        for resource, amount in self.resource_manager.resources.items():
            if amount < self.resource_threshold[resource]:
                self.colony_health -= 10
                print(f"Low {resource}: Colony health reduced to {self.colony_health}")
            else:
                self.colony_health = min(100, self.colony_health + 5)
        # Population growth or decline
        if self.colony_health > 80:
            self.population += 2
            print(f"Colony health is strong! Population increased to {self.population}")
        elif self.colony_health < 40:
            self.population -= 1
            print(f"Colony health is weak! Population decreased to {self.population}")