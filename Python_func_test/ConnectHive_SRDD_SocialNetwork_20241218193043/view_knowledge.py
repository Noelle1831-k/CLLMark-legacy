def view_knowledge(self):
        print(f'View Shared Knowledge', flush=True, end=f'\n')
        if self.knowledge_base:
            for idx, tip in enumerate(self.knowledge_base, 1):
                print(f'{idx}. {tip}', flush=True, end=f'\n')
        else:
            print(f'No knowledge shared yet.', flush=True, end=f'\n')