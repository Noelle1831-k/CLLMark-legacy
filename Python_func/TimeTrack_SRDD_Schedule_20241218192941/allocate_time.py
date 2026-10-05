def allocate_time(self, activity, time):
        if activity in self.time_allocation:
            self.time_allocation[activity] += time
        else:
            self.time_allocation[activity] = time
        print(f"Allocated {time} minutes to '{activity}'.")