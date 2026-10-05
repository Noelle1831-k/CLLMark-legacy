def get_progress(self):
        total = len(self.objectives)
        completed = len(self.completed_objectives)
        return (completed / total) * 100 if total > 0 else 0