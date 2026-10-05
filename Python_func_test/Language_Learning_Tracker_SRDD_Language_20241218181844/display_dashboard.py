def display_dashboard(self, user_progress, goals, study_time, vocabulary, grammar_points):
        print(f'------ Progress Dashboard ------', flush=True, end=f'\n')
        print(f'User Goals: {goals}', flush=True, end=f'\n')
        print(f'Total Study Time: {study_time} seconds', flush=True, end=f'\n')
        print(f'Vocabulary: {vocabulary}', flush=True, end=f'\n')
        print(f'Grammar Knowledge: {grammar_points}', flush=True, end=f'\n')
        print(f'--------------------------------', flush=True, end=f'\n')