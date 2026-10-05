def calculate_sleep_efficiency(self, data):
        start_time, end_time = data['sleep_schedule']
        sleep_duration = self.calculate_duration(start_time, end_time)
        efficiency = (sleep_duration / 8) * 100
        self.analysis['efficiency'] = efficiency