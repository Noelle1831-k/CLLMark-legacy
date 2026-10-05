def track_completion_time(self, task, completion_time):
        '''
        Track how long it took for a task to be completed.
        '''
        try:
            start_time = datetime.strptime(task.deadline, "%Y-%m-%d")
            completion_time = datetime.strptime(completion_time, "%Y-%m-%d")
            time_taken = (completion_time - start_time).days
            self.completion_times.append({"Task": task.name, "TimeTaken": time_taken})
        except ValueError as e:
            print(f"Error parsing dates: {e}")