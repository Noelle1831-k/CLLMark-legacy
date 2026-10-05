def validate_details(self):
        if not self.event_type or not self.date or not self.venue:
            return False
        if self.guest_count <= 0 or self.budget <= 0:
            return False
        return True