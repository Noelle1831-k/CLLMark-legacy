def recruit_volunteer(self, name):
        if name not in self.volunteers:
            self.volunteers[name] = 0
            print(f"Recruited volunteer: {name}")