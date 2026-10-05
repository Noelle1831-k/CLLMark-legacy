def apply_air_resistance(self, car):
        air_resistance_force = self.air_resistance_coefficient * car.speed ** 2
        car.speed -= air_resistance_force
        if car.speed < 0:
            car.speed = 0