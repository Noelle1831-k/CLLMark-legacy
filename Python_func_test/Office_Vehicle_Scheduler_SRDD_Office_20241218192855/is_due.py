def is_due(self, current_date):
        return not self.is_complete and self.service_date <= current_date