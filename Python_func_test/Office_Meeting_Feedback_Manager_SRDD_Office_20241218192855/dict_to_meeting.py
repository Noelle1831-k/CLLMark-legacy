def dict_to_meeting(self, meeting_dict):
        meeting = Meeting(meeting_dict['meeting_id'], meeting_dict['title'], meeting_dict['date'])
        for feedback_dict in meeting_dict['feedback_list']:
            feedback = self.dict_to_feedback(feedback_dict)
            meeting.add_feedback(feedback)
        return meeting