def render_vehicle(self, vehicle, vehicle_index):
        # Render the vehicle on the screen at its current position
        vehicle_image = self.vehicle_images[vehicle_index]
        self.screen.blit(vehicle_image, vehicle.position)