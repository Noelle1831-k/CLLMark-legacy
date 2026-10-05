def add_team(self, name):
        if name not in self.teams:
            self.teams[name] = Team(name)
            print(f"Team {name} added successfully.")
        else:
            print(f"Team {name} already exists.")