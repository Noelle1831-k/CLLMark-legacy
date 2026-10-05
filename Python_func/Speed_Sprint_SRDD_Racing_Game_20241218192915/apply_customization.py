def apply_customization(self):
        # Apply customizations to enhance vehicle performance
        if "nitro_boost" in self.customizations:
            self.acceleration += self.customizations["nitro_boost"]
        if "weight_reduction" in self.customizations:
            self.max_speed += self.customizations["weight_reduction"]
        print(f"Final vehicle stats: Acceleration={self.acceleration}, Max Speed={self.max_speed}")