def activate(self):
        if not self.active:
            self.active = True
            print(f"Activating power-up: {self.name}")
        else:
            print(f"Power-up {self.name} is already active.")