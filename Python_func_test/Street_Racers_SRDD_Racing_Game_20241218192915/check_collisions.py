def check_collisions(self, car, track):
        if car.position[0] >= len(track.layout):
            car.velocity[0] = 0
            car.velocity[1] = 0