def feedback_to_dict(self, feedback):
        return {
            'employee_id': feedback.employee_id,
            'comments': feedback.comments,
            'rating': feedback.rating
        }