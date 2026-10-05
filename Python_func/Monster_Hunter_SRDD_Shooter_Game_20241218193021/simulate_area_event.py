def simulate_area_event(self, area_id):
        '''
        Simulate a random event occurring in the specified area.
        Events include treasure spawns, ambushes, or rare monster sightings.
        '''
        if 1 <= area_id <= self.areas_unlocked:
            events = [
                "A rare treasure chest has appeared!",
                "You have been ambushed by a group of monsters!",
                "A rare monster has been sighted in this area!",
                "Nothing unusual happened. It's a calm day.",
                "A mysterious traveler offers to sell rare items."
            ]
            event = random.choice(events)
            print(f"Event in Area {area_id}: {event}")
            return event
        else:
            print(f"Area {area_id} is not unlocked or does not exist.")
            return None