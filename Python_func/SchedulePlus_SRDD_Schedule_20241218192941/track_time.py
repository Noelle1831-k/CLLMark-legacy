def track_time(self, task_name, time_spent):
        if task_name in self.time_log:
            self.time_log[task_name]['tracked'] += float(time_spent.split()[0])