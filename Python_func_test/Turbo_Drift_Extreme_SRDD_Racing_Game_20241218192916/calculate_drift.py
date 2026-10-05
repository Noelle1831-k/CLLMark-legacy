def calculate_drift(self, car):
        drift_factor = math.sin(car.handling) * car.speed / 100
        if drift_factor > self.drift_threshold:
            car.speed -= drift_factor
            print(f"Drifting with factor: {drift_factor}")
        else:
            print("Stable driving, no drift.")