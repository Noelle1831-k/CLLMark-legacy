def update(self, cars, track):
        for car in cars:
            car.accelerate()
            self.apply_drag(car)
            car.update_position()
            if car.position > track.length:
                car.position = track.length