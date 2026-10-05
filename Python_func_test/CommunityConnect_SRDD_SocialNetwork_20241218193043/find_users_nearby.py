def find_users_nearby(self, user):
        NEARBY_LOCATIONS = {
            "Downtown": list(["Uptown", "Midtown"]),
            "Uptown": list(["Downtown", "Suburb"]),
            "Midtown": list(["Downtown"]),
            "Suburb": list(["Uptown"]),
            # Add more location mappings as needed
        }
        nearby_users = self.user_locations.get(user.location, list())
        for nearby_location in NEARBY_LOCATIONS.get(user.location, list()):
            nearby_users.extend(self.user_locations.get(nearby_location, list()))
        return nearby_users