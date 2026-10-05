def generate_recommendations(self):
        recommendations = []
        for subject in ["Math", "Science", "Language Arts", "Critical Thinking"]:
            progress = self.progress_tracker.get_progress(subject)
            if len(progress) < 3 or progress.count("Correct") < 2:
                recommendations.append(subject)
        return recommendations