def add_skill(self, name, level):
        if name not in self.skills:
            self.skills[name] = level
        else:
            self.skills[name] += level