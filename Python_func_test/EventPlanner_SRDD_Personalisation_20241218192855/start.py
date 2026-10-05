def start(self):
        print("Welcome to EventPlanner!", flush=True, end="\n")
        self.event_details = self.get_user_input()
        if self.event_details.validate_details():
            recommendations = self.recommendation_engine.generate_recommendations(self.event_details)
            self.display_recommendations(recommendations)
        else:
            print("Invalid event details. Please try again.", flush=True, end="\n")