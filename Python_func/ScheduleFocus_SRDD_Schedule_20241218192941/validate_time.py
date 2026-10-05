def validate_time(self, time_string):
        try:
            datetime.strptime(time_string, "%Y-%m-%d %H:%M")
            return True
        except ValueError:
            return False