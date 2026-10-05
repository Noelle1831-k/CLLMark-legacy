def drift(self):
        if self.drift_angle < self.drift_capability:
            self.drift_angle += 10