def calculate_duration(self, start, end):
        start_hour, start_minute = map(int, start.split(':'))
        end_hour, end_minute = map(int, end.split(':'))
        duration = (end_hour - start_hour) + (end_minute - start_minute) / 60
        return duration