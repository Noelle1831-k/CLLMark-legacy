def check_obstacle(self, position):
        return [obstacle for obstacle in self.obstacles if obstacle[0] == position]