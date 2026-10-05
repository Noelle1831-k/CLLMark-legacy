def display_recommendations(self):
        exercises = self.recommender.recommend_exercises(self.user)
        repertoire = self.recommender.suggest_repertoire(self.user)
        technique = self.recommender.improve_technique(self.user)
        print("Recommended Exercises:", exercises)
        print("Suggested Repertoire:", repertoire)
        print("Technique Improvement Tips:", technique)