def add_pet(self, pet):
        if isinstance(pet, Pet):
            self.pets.append(pet)