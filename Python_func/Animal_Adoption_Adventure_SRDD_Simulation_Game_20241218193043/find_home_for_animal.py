def find_home_for_animal(self, animal):
        if animal in self.animals and not animal.adoption_status:
            animal.update_adoption_status(True)
            self.remove_animal(animal)
            print(f"Found a home for {animal.name}.")