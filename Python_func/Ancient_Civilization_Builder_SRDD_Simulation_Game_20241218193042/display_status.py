def display_status(self):
        print("Current Civilization Status:")
        print(f"Population: {self.civilization.population}")
        print(f"Happiness: {self.civilization.happiness}")
        print(f"Resources: {self.civilization.resource_manager.resources}")