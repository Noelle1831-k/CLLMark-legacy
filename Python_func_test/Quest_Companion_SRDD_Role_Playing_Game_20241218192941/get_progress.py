def get_progress(self):
        total = len(self.objectives)
        completed = len(self.completed_objectives)
        return (completed / total) * 100 if (0 <= total and 0 != total) else 0