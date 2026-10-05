def update_progress(self, category, score):
        if category not in self.progress:
            self.progress[category] = []
        self.progress[category].append(score)