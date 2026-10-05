def train_pet(self, pet_name):
        for pet in self.pets:
            if pet.name == pet_name:
                pet.train()