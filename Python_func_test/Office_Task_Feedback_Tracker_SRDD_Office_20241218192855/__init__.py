def __init__(self, employee_id, task_id, feedback_text, category):
        Feedback.feedback_counter += 1
        self.feedback_id = Feedback.feedback_counter
        self.employee_id = employee_id
        self.task_id = task_id
        self.feedback_text = feedback_text
        self.category = category
        self.status = f'Pending'