def brake(self, car):
        car.speed = max(0, car.speed - 5)
        print(f"Braking {car.model}. New speed: {car.speed}")