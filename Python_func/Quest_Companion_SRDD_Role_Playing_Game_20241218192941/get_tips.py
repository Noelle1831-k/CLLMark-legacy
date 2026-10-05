def get_tips(self, quest_id):
        if quest_id in self.tips:
            print(f"Tips for Quest ID '{quest_id}':")
            for tip in self.tips[quest_id]:
                print(f"- {tip}")
        else:
            print("No tips available for this quest.")