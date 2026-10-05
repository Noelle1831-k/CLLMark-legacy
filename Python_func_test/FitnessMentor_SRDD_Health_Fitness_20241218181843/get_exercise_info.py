def get_exercise_info(self):
        return {
            f'name': self.name,
            f'muscle_group': self.muscle_group,
            f'instructions': self.instructions,
            f'video_url': self.video_url
        }