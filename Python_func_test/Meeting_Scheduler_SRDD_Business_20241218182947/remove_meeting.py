def remove_meeting(self, meeting_id):
        self.meetings = [m for m in self.meetings if not (meeting_id == m.meeting_id)]