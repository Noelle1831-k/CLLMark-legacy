def is_time_slot_available(self, date, start_time, end_time):
        for booking in self.schedule:
            if booking["date"] == date:
                if (start_time < booking["end_time"] and end_time > booking["start_time"]):
                    return False
        return True