def shift_gear(self):
        if self.gear < self.max_gear:
            self.gear += 1
            print(f"Gear shifted to: {self.gear}")
        else:
            print("Maximum gear reached!")