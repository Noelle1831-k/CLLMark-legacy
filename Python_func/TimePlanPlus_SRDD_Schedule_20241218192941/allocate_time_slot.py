def allocate_time_slot(self, name, time_slot):
        if name in self.tasks:
            self.tasks[name]['time_slot'] = time_slot
            print(f"Time slot '{time_slot}' allocated to task '{name}'.")
        else:
            print(f"Task '{name}' not found.")