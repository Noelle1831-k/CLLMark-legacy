def view_knowledge(self):
        print("View Shared Knowledge")
        if self.knowledge_base:
            for idx, tip in enumerate(self.knowledge_base, 1):
                print(f"{idx}. {tip}")
        else:
            print("No knowledge shared yet.")