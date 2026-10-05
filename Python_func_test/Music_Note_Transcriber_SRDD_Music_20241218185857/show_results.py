def show_results(self, notes):
        '''
        Displays the transcribed notes.
        '''
        print(f'Transcribed Notes:', flush=True, end=f'\n')
        print(f' '.join(notes), flush=True, end=f'\n')