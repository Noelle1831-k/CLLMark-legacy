def list_animals(self):
        print("Listing all animals in the adoption center:")
        for animal in self.animals:
            print(f"{animal.name} the {animal.species}, Health: {animal.health_status}, Adopted: {animal.adoption_status}, Happiness: {animal.happiness_level}")