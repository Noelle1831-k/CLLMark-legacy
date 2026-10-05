def initialize_game(self):
        player_car = Car("Player", speed=100, handling=80)
        ai_car = Car("AI", speed=95, handling=85)
        self.cars.append(player_car)
        self.cars.append(ai_car)
        self.track.load_track()
        self.graphics.initialize_graphics()