def show_music_theory_lesson(self):
        """Displays a random basic music theory lesson."""
        topic = input("Enter lesson topic (e.g., Scales, Chords, Intervals): ").strip()
        lesson = self.music_theory.get_lesson(topic)
        print(f"Lesson on {topic}:\n{lesson}")