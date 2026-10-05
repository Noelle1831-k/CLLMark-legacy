def improve_technique(self, user):
        # Suggest technique improvements
        techniques = ["Focus on finger positioning", "Improve breath control"]
        if user.skill_level == "advanced":
            techniques.append("Master vibrato and dynamics")
        return techniques