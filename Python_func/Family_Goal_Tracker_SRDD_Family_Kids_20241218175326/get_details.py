def get_details(self):
        return {
            "title": self.title,
            "description": self.description,
            "assigned_member": self.assigned_member.name if self.assigned_member else None,
            "deadline": self.deadline,
            "status": self.status,
            "progress": self.progress  # Include progress in details
        }