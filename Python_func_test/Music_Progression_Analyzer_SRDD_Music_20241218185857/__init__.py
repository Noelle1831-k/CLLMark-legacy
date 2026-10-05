def __init__(self):
        self.midi_processor = midi_processor.MIDIProcessor()
        self.chord_analyzer = chord_analyzer.ChordAnalyzer()
        self.visualization = visualization.Visualization()
        self.user_input_handler = user_input_handler.UserInputHandler()