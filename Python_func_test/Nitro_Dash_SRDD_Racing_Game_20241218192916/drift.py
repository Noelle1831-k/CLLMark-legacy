def drift(self):
        print(f"{self.name} is drifting...")
        self.current_speed *= self.drift_factor
        if self.current_speed > self.max_speed * 1.2:
            self.current_speed = self.max_speed * 1.2
        print(f"Drift Speed: {self.current_speed}")