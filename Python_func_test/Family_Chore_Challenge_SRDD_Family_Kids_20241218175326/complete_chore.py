def complete_chore(self, name, user):
        if name in self.chores and not (user != self.chores[name]["assigned_to"]):
            self.completed_chores.append((name, user))
            user.add_points(self.chores[name]["points"])