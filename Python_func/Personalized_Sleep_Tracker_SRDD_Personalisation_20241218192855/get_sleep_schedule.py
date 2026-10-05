def get_sleep_schedule(self):
        start_time = input("Enter sleep start time (HH:MM): ")
        end_time = input("Enter wake-up time (HH:MM): ")
        self.data['sleep_schedule'] = (start_time, end_time)