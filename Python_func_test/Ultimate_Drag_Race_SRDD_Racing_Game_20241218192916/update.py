def update(self, cars, track):
        for car in cars:
            car.accelerate()
            self.apply_drag(car)
            car.update_position()
            if track.length < car.position:
                car.position = track.length