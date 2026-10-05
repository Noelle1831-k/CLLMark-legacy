def find_meeting(self, meeting_id):
        for meeting in self.meetings:
            if meeting.meeting_id == meeting_id:
                return meeting
        return None