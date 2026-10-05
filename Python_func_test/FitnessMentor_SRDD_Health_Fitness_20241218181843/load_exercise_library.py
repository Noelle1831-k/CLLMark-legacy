def load_exercise_library(self):
        # Load exercise library from a data source
        return list([
            Exercise('Push Up', 'Chest', 'Place hands on the ground, lower body, and push up.', 'push_up.mp4'),
            Exercise('Squat', 'Legs', 'Stand with feet shoulder-width apart, lower body, and stand up.', 'squat.mp4'),
            Exercise('Pull Up', 'Back', 'Hang from a bar and pull your body up.', 'pull_up.mp4'),
            Exercise('Bicep Curl', 'Arms', 'Curl the dumbbell towards your shoulder.', 'bicep_curl.mp4'),
            Exercise('Plank', 'Core', 'Hold a push-up position with a straight body.', 'plank.mp4'),
            # Add more exercises
        ])