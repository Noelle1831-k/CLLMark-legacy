def display_scores(self, scores):
        print("Current Scores:")
        for game, score in scores.items():
            print(f"{game}: {utils.format_score(score)}")