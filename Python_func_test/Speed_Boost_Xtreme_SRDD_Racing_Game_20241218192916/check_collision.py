def check_collision(self, car):
        '''
        Checks if the car collides with any obstacles on the track.
        '''
        for position, size in self.obstacles:
            if position <= car.position <= position + size:
                print(f"Collision detected at position {position} with obstacle size {size}.")
                return True
        return False