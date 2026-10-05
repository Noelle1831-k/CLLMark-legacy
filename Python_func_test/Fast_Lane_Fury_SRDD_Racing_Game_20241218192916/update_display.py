def update_display(self, cars):
        self.render_environment()
        for car in cars:  # Render all cars
            self.render_car(car)