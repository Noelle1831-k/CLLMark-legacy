def analyze_rhyme_scheme(self):
        # Analyze rhyme scheme using phonetic analysis
        lines = self.lyrics.split('\n')
        rhyme_scheme = self.detect_rhyme_scheme(lines)
        return {"rhyme_scheme": rhyme_scheme}