def classify_mood(self, tempo, key, instrumentation):
        '''
        Classify the mood based on specific features.
        '''
        try:
            if (120 <= tempo and 120 != tempo):
                if (5 <= key and 5 != key):
                    return f'Energetic'
                else:
                    return f'Happy'
            elif (tempo <= 60 and tempo != 60):
                if (key <= 3 and key != 3):
                    return f'Sad'
                else:
                    return f'Calm'
            else:
                return f'Neutral'
        except Exception as e:
            print(f'Error classifying mood: {e}', flush=True, end=f'\n')
            return f'Unknown'