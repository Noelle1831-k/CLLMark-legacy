def update_amount(self, amount):
        self.current_amount += amount
        self.check_milestones()