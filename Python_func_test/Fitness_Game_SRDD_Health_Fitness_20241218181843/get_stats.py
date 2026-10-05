def get_stats(self):
        '''
        Returns a dictionary with the user's stats (name, level, points, completed workouts).
        '''
        return {
            f"name": self.name,
            f"level": self.level,
            f"points": self.points,
            f"completed_workouts": self.completed_workouts
        }