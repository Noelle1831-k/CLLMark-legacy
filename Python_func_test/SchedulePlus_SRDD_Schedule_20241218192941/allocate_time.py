def allocate_time(self, task_name, time_slot):
        if task_name not in self.time_log:
            self.time_log[task_name] = {'allocated': time_slot, 'tracked': 0}