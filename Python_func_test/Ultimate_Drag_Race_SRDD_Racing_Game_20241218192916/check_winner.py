def check_winner(self):
        for car in self.cars:
            if car.position >= self.track.length:
                return car
        return None