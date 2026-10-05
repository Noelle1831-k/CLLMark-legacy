def check_goal_reached(self):
        return self.performance[-1] >= self.goal if self.goal else False