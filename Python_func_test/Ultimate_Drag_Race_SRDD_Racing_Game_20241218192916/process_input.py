def process_input(self, cars):
        # Simulate user input for demonstration purposes
        for car in cars:
            if car.nitro_available and 0.5 * car.max_speed > car.position:
                car.use_nitro()