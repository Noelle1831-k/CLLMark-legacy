def display_conjugation(self, verb):
        '''
        Displays the conjugation of a verb.
        '''
        conjugator = Conjugator(verb)
        tenses = ['present', 'past', 'future']
        moods = ['indicative', 'subjunctive', 'imperative']
        persons = ['first', 'second', 'third']
        for tense in tenses:
            for mood in moods:
                for person in persons:
                    conjugation = conjugator.conjugate(tense, mood, person)
                    if conjugation:
                        print(f"{tense} {mood} {person}: {conjugation}")
                    else:
                        print(f"{tense} {mood} {person}: Not available")