def upgrade(self, attribute, value):
        if attribute == "speed":
            self.speed += value
        elif attribute == "agility":
            self.agility += value