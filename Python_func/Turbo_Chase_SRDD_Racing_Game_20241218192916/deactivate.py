def deactivate(self):
        if self.active:
            self.active = False
            print(f"Deactivating power-up: {self.name}")
        else:
            print(f"Power-up {self.name} is not active.")