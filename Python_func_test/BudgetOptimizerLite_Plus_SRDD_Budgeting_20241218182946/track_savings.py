def track_savings(self, name, target_amount, current_amount):
        savings_tracker = SavingsTracker(name, target_amount)
        savings_tracker.update_current_savings(current_amount)
        self.savings_trackers.append(savings_tracker)
        savings_tracker.track_progress()