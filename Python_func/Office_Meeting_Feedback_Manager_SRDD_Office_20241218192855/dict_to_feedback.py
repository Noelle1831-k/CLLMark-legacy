def dict_to_feedback(self, feedback_dict):
        return Feedback(feedback_dict['employee_id'], feedback_dict['comments'], feedback_dict['rating'])