def overlaps(self, other_slot):
        return not (self.end_time <= other_slot.start_time or self.start_time >= other_slot.end_time)