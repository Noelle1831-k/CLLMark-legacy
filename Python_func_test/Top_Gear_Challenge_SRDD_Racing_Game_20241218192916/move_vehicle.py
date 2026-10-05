def move_vehicle(self, user_input):
        if user_input == "accelerate":
            self.speed += self.acceleration
        elif user_input == "brake":
            self.speed -= 2 * self.acceleration
        self.position += self.speed