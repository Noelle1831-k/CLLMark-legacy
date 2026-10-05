def analyze_library(self, library):
        '''
        Analyzes a library of tracks and returns a list of metadata for each track.
        '''
        analysis = []
        for track in library:
            analysis.append(self.analyze_track(track))
        return analysis