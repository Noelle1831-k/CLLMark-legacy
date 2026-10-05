def process_input(self):
        print("Processing input...")
        for car in self.cars:
            action = self.get_user_action()
            if action == "accelerate":
                self.accelerate(car)
            elif action == "brake":
                self.brake(car)
            elif action == "drift":
                self.drift(car)