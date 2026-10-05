def handle_input(self):
        # Simulated input handling logic
        user_input = self.ui.get_user_input()
        if user_input == "accelerate":
            self.vehicle.accelerate()
        elif user_input == "brake":
            self.vehicle.brake()
        elif user_input == "left":
            self.vehicle.steer(-1)
        elif user_input == "right":
            self.vehicle.steer(1)
        elif user_input == "quit":
            self.running = False