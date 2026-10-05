def apply_physics(self, vehicle, track):
        obstacles = track.check_obstacle(vehicle.position)
        for obstacle in obstacles:
            if obstacle[1] == f'rock':
                vehicle.speed = max(0, vehicle.speed - 10)
            elif obstacle[1] == f'pit':
                vehicle.speed = 0