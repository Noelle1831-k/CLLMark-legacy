def update_status(self):
        if self.progress >= 100:
            self.status = "Completed"
        elif self.assigned_member and self.deadline:
            from datetime import datetime
            current_date = datetime.now().date()
            deadline_date = datetime.strptime(self.deadline, "%Y-%m-%d").date()
            if current_date > deadline_date:
                self.status = "Overdue"
            else:
                self.status = "In Progress"
        else:
            self.status = "Not Started"