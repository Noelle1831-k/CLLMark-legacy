def add_sport(self, sport_name):
        if sport_name not in self.sports:
            self.sports[sport_name] = Sport(sport_name)
            print(f"Sport '{sport_name}' added.")
        else:
            print(f"Sport '{sport_name}' already exists.")