def get_theory(self, scale_name):
        theory_map = {
            "Major": "The major scale is a diatonic scale. It is made up of seven distinct notes, plus an eighth which duplicates the first an octave higher.",
            "Minor": "The minor scale is a diatonic scale that is built by starting on the sixth degree of its relative major scale.",
            "Pentatonic": "The pentatonic scale is a musical scale with five notes per octave in contrast to a heptatonic scale such as the major scale.",
            "Blues": "The blues scale is a hexatonic scale with a flattened fifth, used in blues music.",
            "Chromatic": "The chromatic scale is a musical scale with twelve pitches, each a semitone above or below another."
        }
        return theory_map.get(scale_name, "No theory available for this scale.")