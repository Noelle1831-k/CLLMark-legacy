def allocate_time_slot(self, task, time_slot):
        if task not in self.schedule:
            self.schedule[task] = time_slot
            print(f"Time slot '{time_slot}' allocated to task '{task}'.")
        else:
            print(f"Task '{task}' already has a time slot.")