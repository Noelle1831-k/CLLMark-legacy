def generate_summary(self):
        total_shots = len(self.entries)
        hits = sum(1 for shot in self.entries if shot.result == "hit")
        misses = total_shots - hits
        accuracy = (hits / total_shots) * 100 if total_shots > 0 else 0
        print(f"Training Summary:\nTotal Shots: {total_shots}\nHits: {hits}\nMisses: {misses}\nOverall Accuracy: {accuracy:.2f}%")