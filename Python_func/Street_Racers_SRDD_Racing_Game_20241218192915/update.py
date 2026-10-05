def update(self, cars):
        for car in cars:
            if car.position[0] > 50:
                print(f"Police chasing {car.name}")