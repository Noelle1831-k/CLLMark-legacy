def main():
    '''
    Main function to run the application.
    '''
    user_input = get_user_input()
    audio_processor = AudioProcessor()
    mood_analyzer = MoodAnalyzer()
    visualizer = Visualizer()
    audio_data = audio_processor.load_audio(user_input)
    if audio_data is None:
        print("Failed to load audio. Exiting the application.")
        return
    features = audio_processor.extract_features(audio_data)
    if features is None:
        print("Failed to extract features. Exiting the application.")
        return
    mood_data = mood_analyzer.analyze_mood(features)
    if mood_data is None:
        print("Failed to analyze mood. Exiting the application.")
        return
    charts = visualizer.generate_charts(mood_data)
    if charts is None:
        print("Failed to generate charts. Exiting the application.")
        return
    visualizer.display_visualizations(charts)