def get_status(self):
        return {"goal": self.goal, "total_expenses": self.total_expenses, "remaining": self.goal - self.total_expenses}