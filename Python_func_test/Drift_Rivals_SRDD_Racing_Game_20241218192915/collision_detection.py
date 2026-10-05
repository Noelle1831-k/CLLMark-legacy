def collision_detection(self, car, track):
        for boundary in track.layout:
            if self.is_collision(car.position, boundary):
                car.speed = 0