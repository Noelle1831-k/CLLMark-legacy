def check_completion(self):
        # Check if the current grid matches the target shape
        return self.grid.matches_target(self.target_shape)