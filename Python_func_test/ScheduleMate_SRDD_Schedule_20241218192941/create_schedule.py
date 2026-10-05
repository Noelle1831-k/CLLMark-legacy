def create_schedule(self, name):
        new_schedule = schedule.Schedule(name)
        self.schedules.append(new_schedule)
        return new_schedule