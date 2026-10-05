def match_criteria(self, event_details):
        if self.cost <= event_details.budget and self.availability == event_details.date:
            return True
        return False