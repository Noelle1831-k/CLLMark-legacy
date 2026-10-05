def share_knowledge(self):
        print("Share Knowledge")
        tip = input("Enter your beekeeping tip or technique: ")
        self.knowledge_base.append(tip)
        print("Thank you for sharing your knowledge!")