def explain_scale(self, scale):
        if not scale.pitches:
            print(f'No scale to explain.', flush=True, end=f'\n')
            return
        intervals = scale.intervals
        explanation = f'The scale starting with {scale.root} follows intervals: {intervals}.'
        print(f'Explaining scale:', explanation, flush=True, end=f'\n')