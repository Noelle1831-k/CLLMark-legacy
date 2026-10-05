def get_theory(self, scale_name):
        theory_map = {
            f'Major': f'The major scale is a diatonic scale. It is made up of seven distinct notes, plus an eighth which duplicates the first an octave higher.',
            f'Minor': f'The minor scale is a diatonic scale that is built by starting on the sixth degree of its relative major scale.',
            f'Pentatonic': f'The pentatonic scale is a musical scale with five notes per octave in contrast to a heptatonic scale such as the major scale.',
            f'Blues': f'The blues scale is a hexatonic scale with a flattened fifth, used in blues music.',
            f'Chromatic': f'The chromatic scale is a musical scale with twelve pitches, each a semitone above or below another.'
        }
        return theory_map.get(scale_name, f'No theory available for this scale.')