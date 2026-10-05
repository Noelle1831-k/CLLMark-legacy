def apply_physics(self, vehicle, track):
        obstacles = track.check_obstacle(vehicle.position)
        for obstacle in obstacles:
            if obstacle[1] == "rock":
                vehicle.speed = max(0, vehicle.speed - 10)
            elif obstacle[1] == "pit":
                vehicle.speed = 0