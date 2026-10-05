def is_conflict(self, other_booking):
        return self.vehicle_id == other_booking.vehicle_id and not (self.end_time <= other_booking.start_time or self.start_time >= other_booking.end_time)