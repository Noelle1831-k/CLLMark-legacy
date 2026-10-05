def main():
    '''
    Main function to execute the board game score prediction workflow.
    '''
    # Load and preprocess data
    data_loader = GameDataLoader()
    raw_data = data_loader.load_data('game_data.csv')
    preprocessed_data = data_loader.preprocess_data(raw_data)
    # Extract features
    feature_extractor = FeatureExtractor()
    features, labels = feature_extractor.extract_features(preprocessed_data)
    # Train model
    model_trainer = ModelTrainer()
    model = model_trainer.train_model(features, labels)
    # Predict scores
    score_predictor = ScorePredictor(model)
    predictions = score_predictor.predict_scores(features)
    # Evaluate predictions
    evaluator = PredictionEvaluator()
    r2_score = evaluator.evaluate(predictions, labels)
    print(f'Prediction R^2 Score: {r2_score:.2f}%')