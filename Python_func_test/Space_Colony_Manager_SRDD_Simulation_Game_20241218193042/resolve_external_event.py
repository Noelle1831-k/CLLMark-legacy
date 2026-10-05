def resolve_external_event(self, event):
        '''
        Handles external events or challenges that can impact the colony's state.
        '''
        print(f"Resolving external event: {event}")
        impact = choice(["positive", "negative", "neutral"])
        if impact == "positive":
            self.resource_manager.resources["food"] += 20
            self.resource_manager.resources["water"] += 20
            self.resource_manager.resources["energy"] += 20
            print("The event had a positive impact! Resources boosted.")
        elif impact == "negative":
            self.resource_manager.resources["food"] -= 15
            self.resource_manager.resources["water"] -= 15
            self.resource_manager.resources["energy"] -= 15
            self.colony_health -= 10
            print("The event had a negative impact! Resources and health reduced.")
        else:
            print("The event had no significant impact.")