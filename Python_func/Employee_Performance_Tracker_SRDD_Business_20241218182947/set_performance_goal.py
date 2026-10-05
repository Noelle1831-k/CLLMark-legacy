def set_performance_goal(self, goal):
        if isinstance(goal, PerformanceGoal):
            self.goals.append(goal)