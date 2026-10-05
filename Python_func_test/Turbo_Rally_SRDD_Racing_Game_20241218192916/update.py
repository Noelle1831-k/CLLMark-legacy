def update(self):
        self.input_handler.get_input()
        self.vehicle.update_physics()
        self.weather.update_weather()
        self.track.check_collision(self.vehicle)