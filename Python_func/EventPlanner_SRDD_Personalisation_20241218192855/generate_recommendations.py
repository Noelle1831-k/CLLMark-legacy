def generate_recommendations(self, event_details):
        all_vendors = self.database.get_vendors()
        return self.filter_vendors(all_vendors, event_details)