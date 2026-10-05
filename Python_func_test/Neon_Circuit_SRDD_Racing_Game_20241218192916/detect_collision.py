def detect_collision(self, vehicle, track):
        # Define vehicle's bounding box
        vehicle_width = 5  # Example width
        vehicle_height = 5  # Example height
        vehicle_bbox = (
            vehicle.position[0] - vehicle_width / 2,
            vehicle.position[1] - vehicle_height / 2,
            vehicle.position[0] + vehicle_width / 2,
            vehicle.position[1] + vehicle_height / 2
        )
        # Check collision with each obstacle
        for obstacle in track.obstacles:
            obstacle_bbox = (
                obstacle[0] - 2.5,  # Example obstacle size
                obstacle[1] - 2.5,
                obstacle[0] + 2.5,
                obstacle[1] + 2.5
            )
            if self.bbox_intersect(vehicle_bbox, obstacle_bbox):
                print("Collision detected!")
                return True
        return False