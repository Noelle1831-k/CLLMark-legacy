def share_schedule(self, schedule, user):
        if schedule in self.schedules:
            schedule.add_shared_user(user)
            user.add_schedule(schedule)