def track_progress(self):
        progress_percentage = (self.current_amount / self.target_amount) * 100
        print(f"Savings Progress for {self.name}: {progress_percentage:.2f}%")