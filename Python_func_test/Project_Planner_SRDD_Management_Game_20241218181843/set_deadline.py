def set_deadline(self, deadline_str):
        self.deadline = parse_date(deadline_str)
        if self.deadline:
            print(f"Deadline for task '{self.name}' set to {self.deadline}.")