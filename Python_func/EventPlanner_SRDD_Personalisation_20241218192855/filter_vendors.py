def filter_vendors(self, vendors, event_details):
        recommended_vendors = []
        for vendor in vendors:
            if vendor.match_criteria(event_details):
                recommended_vendors.append(vendor)
        return recommended_vendors