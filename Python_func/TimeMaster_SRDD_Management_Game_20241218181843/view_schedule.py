def view_schedule(self):
        if not self.schedules:
            print("No schedules available.")
        else:
            print("Your schedules:")
            for i, schedule in enumerate(self.schedules, 1):
                print(f"{i}. {schedule}")