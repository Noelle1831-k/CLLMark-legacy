def render(self):
        self.ui.display_speed(self.car.speed)
        self.ui.display_boost_status(self.car.boost_active)
        self.ui.display_lap_time(self.lap_time)