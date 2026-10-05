def reward_family(self):
        if self.family_goal and len(self.family_progress) > 0 and self.family_progress[-1] >= 5:
            print(f"Congratulations! {self.family_name} family has achieved the goal: {self.family_goal}")
        else:
            print(f"{self.family_name} family has not yet achieved the goal: {self.family_goal}")