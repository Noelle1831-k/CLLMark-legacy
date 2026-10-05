def get_special_ability(self):
        if self.type == "car":
            return self.boost
        elif self.type == "bike":
            return self.jump