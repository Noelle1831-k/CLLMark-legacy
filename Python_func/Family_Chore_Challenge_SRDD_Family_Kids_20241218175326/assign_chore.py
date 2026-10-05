def assign_chore(self, name, user):
        if name in self.chores:
            self.chores[name]["assigned_to"] = user