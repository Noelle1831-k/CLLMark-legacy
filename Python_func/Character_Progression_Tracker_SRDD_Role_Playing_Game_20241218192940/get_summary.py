def get_summary(self):
        summary = f"Name: {self.name}\nLevel: {self.level}\n"
        summary += f"Attributes: {', '.join(self.attributes)}\n"
        summary += f"Skills: {', '.join(self.skills)}\n"
        summary += f"Equipment: {', '.join(self.equipment)}\n"
        return summary