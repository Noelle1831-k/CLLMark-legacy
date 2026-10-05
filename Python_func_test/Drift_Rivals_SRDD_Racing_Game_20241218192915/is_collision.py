def is_collision(self, position, boundary):
        return abs(position[0] - boundary[0]) < 5 and abs(position[1] - boundary[1]) < 5