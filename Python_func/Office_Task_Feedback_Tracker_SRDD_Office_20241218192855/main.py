def main():
    # Initialize system
    feedback_system = FeedbackSystem()
    # Create employees and managers
    emp1 = Employee(employee_id=1, name="Alice", department="Engineering")
    emp2 = Employee(employee_id=2, name="Bob", department="Marketing")
    emp3 = Employee(employee_id=3, name="Eve", department="HR")
    mgr1 = Manager(manager_id=1, name="Charlie", department="Engineering")
    mgr2 = Manager(manager_id=2, name="David", department="Marketing")
    # Employees submit feedback
    feedback_system.submit_feedback(emp1.employee_id, task_id=101, feedback_text="Need more resources", category="Resource")
    feedback_system.submit_feedback(emp2.employee_id, task_id=102, feedback_text="Deadline too tight", category="Time")
    feedback_system.submit_feedback(emp3.employee_id, task_id=103, feedback_text="Need better communication", category="Communication")
    # Manager reviews feedback
    feedback_system.review_feedback(mgr1.manager_id)
    feedback_system.review_feedback(mgr2.manager_id)
    # Track specific feedback
    status = feedback_system.track_feedback(feedback_id=1)
    print(f"Status of Feedback ID 1: {status}")
    # Categorize feedback
    feedback_system.categorize_feedback(feedback_id=1, category="Urgent")