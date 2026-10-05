def update_goal(self, name, amount=None, deadline=None):
        for goal in self.goals:
            if goal['name'] == name:
                if amount is not None:
                    goal['amount'] = amount
                if deadline is not None:
                    goal['deadline'] = deadline