def get_score_history(self):
        correct_count = sum(self.score_history)
        total = len(self.score_history)
        print(f"You spelled {correct_count} out of {total} words correctly.")