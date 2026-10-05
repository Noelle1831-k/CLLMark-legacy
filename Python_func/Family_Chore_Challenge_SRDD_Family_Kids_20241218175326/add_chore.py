def add_chore(self, name, points, deadline):
        self.chores[name] = {"points": points, "deadline": deadline, "assigned_to": None}