def is_available(self, start_time, end_time):
        for slot in self.availability:
            if start_time >= slot.start_time and slot.end_time >= end_time:
                return True
        return False