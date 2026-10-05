def meeting_to_dict(self, meeting):
        return {
            'meeting_id': meeting.meeting_id,
            'title': meeting.title,
            'date': meeting.date,
            'feedback_list': [self.feedback_to_dict(feedback) for feedback in meeting.get_feedback()]
        }