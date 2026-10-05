def check_collisions(self, player, track):
        if player.position in track.get_obstacles():
            print("Collision detected!")
            player.vehicle.speed = max(0, player.vehicle.speed - 50)