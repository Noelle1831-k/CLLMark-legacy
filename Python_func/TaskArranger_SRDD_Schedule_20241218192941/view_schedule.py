def view_schedule(self):
        print("Schedule Overview:")
        for task, time_slot in self.schedule.items():
            print(f"Task: {task}, Time Slot: {time_slot}")