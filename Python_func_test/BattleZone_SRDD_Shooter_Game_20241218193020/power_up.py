def power_up(self, power_up):
        if power_up.type == "Health":
            self.health += 20
        elif power_up.type == "Speed":
            self.speed += 2