def run(self):
        print("Starting Language Pronunciation Analyzer...")
        self.recorder.record_audio()
        self.recorder.save_audio("recorded_audio.wav")
        self.processor.load_audio("recorded_audio.wav")
        self.processor.process_audio()
        self.analyzer.analyze_pronunciation(self.processor.processed_audio)
        self.analyzer.generate_report()