def update_game_state(self):
        self.vehicle.accelerate()
        self.police.chase_player()
        self.city.update_city_conditions()
        self.player_distance += self.vehicle.speed
        self.police_distance += self.police.speed
        print(f"Player distance: {self.player_distance}, Police distance: {self.police_distance}")