def main():
    file_handler = FileHandler()
    audio_analyzer = AudioAnalyzer()
    genre_predictor = GenrePredictor()
    confidence_calculator = ConfidenceCalculator()
    # Example input
    audio_input = "path/to/audio/file.mp3"  # or a URL
    # Process input
    audio_data = file_handler.process_input(audio_input)
    # Analyze audio
    features = audio_analyzer.extract_features(audio_data)
    # Predict genre
    genre, probabilities = genre_predictor.predict_genre(features)
    # Calculate confidence
    confidence_score, confidence_level = confidence_calculator.calculate_confidence(probabilities)
    # Output results
    print(f"Predicted Genre: {genre}")
    print(f"Confidence Score: {confidence_score:.2f}%")
    print(f"Confidence Level: {confidence_level}")
    # Detailed confidence report
    report = confidence_calculator.detailed_confidence_report(probabilities)
    print("Detailed Confidence Report:")
    for genre, details in report.items():
        print(f"{genre}: {details}")