def view_rewards(self):
        for achievement in self.achievements:
            if achievement.status == 'Completed':
                print(f"Reward for {achievement.name}: {achievement.calculate_reward()}")