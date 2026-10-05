def get_chore_points(self, chore_name):
        return self.chores[chore_name]["points"] if chore_name in self.chores else 0