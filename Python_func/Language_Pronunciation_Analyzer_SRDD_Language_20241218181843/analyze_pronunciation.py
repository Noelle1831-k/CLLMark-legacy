def analyze_pronunciation(self, processed_audio):
        self.analysis_result = utils.compare_with_standard(processed_audio)