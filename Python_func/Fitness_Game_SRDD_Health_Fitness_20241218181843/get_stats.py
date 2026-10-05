def get_stats(self):
        '''
        Returns a dictionary with the user's stats (name, level, points, completed workouts).
        '''
        return {
            "name": self.name,
            "level": self.level,
            "points": self.points,
            "completed_workouts": self.completed_workouts
        }