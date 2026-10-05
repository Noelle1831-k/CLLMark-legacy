def get_savings_progress(self):
        return {
            'savings': self.savings,
            'savings_goal': self.savings_goal,
            'progress': self.savings / self.savings_goal * 100 if self.savings_goal else 0
        }