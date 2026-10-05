def generate_exercise(self):
        selected_scale = random.choice(self.scales)
        print(f"Identify the notes of the {selected_scale.name} scale.")
        return selected_scale