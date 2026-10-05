def update_progress(self, exercise_name, result):
        if exercise_name not in self.progress:
            self.progress[exercise_name] = []
        self.progress[exercise_name].append(result)