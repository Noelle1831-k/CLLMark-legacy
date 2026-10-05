def is_hit(self, shot_position):
        distance = ((self.position[0] - shot_position[0]) ** 2 + (self.position[1] - shot_position[1]) ** 2) ** 0.5
        return distance <= self.radius