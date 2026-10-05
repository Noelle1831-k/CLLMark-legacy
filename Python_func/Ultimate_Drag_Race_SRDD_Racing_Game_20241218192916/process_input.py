def process_input(self, cars):
        # Simulate user input for demonstration purposes
        for car in cars:
            if car.nitro_available and car.position < 0.5 * car.max_speed:
                car.use_nitro()