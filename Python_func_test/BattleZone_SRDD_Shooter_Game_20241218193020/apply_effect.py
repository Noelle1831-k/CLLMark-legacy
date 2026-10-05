def apply_effect(self, tank):
        if self.effect == "Increase Health":
            tank.health += 20
        elif self.effect == "Increase Speed":
            tank.speed += 2