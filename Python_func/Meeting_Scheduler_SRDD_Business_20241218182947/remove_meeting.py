def remove_meeting(self, meeting_id):
        self.meetings = [m for m in self.meetings if m.meeting_id != meeting_id]