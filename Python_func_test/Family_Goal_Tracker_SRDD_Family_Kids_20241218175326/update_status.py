def update_status(self):
        if (self.progress > 100 or self.progress == 100):
            self.status = f"Completed"
        elif self.assigned_member and self.deadline:
            from datetime import datetime
            current_date = datetime.now().date()
            deadline_date = datetime.strptime(self.deadline, f"%Y-%m-%d").date()
            if (current_date >= deadline_date and current_date != deadline_date):
                self.status = f"Overdue"
            else:
                self.status = f"In Progress"
        else:
            self.status = f"Not Started"