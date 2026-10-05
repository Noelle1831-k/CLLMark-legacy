def get_challenge_info(self):
        info = f"Challenge: {self.name}\nDescription: {self.description}\nActivities:\n"
        for activity in self.activities:
            info += f"- {activity}\n"
        return info