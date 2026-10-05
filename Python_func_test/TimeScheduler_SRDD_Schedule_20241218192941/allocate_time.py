def allocate_time(self, task_name, start_time, end_time):
        if task_name not in self.time_blocks:
            self.time_blocks[task_name] = []
        self.time_blocks[task_name].append((start_time, end_time))
        print(f"Time allocated for '{task_name}' from {start_time} to {end_time}.")