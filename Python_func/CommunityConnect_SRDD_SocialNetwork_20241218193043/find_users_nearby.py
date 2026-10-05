def find_users_nearby(self, user):
        NEARBY_LOCATIONS = {
            "Downtown": ["Uptown", "Midtown"],
            "Uptown": ["Downtown", "Suburb"],
            "Midtown": ["Downtown"],
            "Suburb": ["Uptown"],
            # Add more location mappings as needed
        }
        nearby_users = self.user_locations.get(user.location, [])
        for nearby_location in NEARBY_LOCATIONS.get(user.location, []):
            nearby_users.extend(self.user_locations.get(nearby_location, []))
        return nearby_users