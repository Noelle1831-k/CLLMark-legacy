def calculate_trajectory(self, target):
        return self.ballistics.compute_trajectory(target.position, self.scope_adjustment)