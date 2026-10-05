def start_game(self):
        print("Welcome to Space Colony Manager!")
        self.planet.generate_planet()
        self.colony.initialize_colony(self.planet)