def calculate_duration(self, start_time, end_time):
        start = datetime.strptime(start_time, "%Y-%m-%d %H:%M")
        end = datetime.strptime(end_time, "%Y-%m-%d %H:%M")
        duration = end - start
        return duration.total_seconds() / 3600