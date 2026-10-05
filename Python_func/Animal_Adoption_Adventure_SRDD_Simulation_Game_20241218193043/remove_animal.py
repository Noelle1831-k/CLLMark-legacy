def remove_animal(self, animal):
        if animal in self.animals:
            self.animals.remove(animal)
            print(f"Removed {animal.name} from the adoption center.")