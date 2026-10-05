def main():
    # Initialize components
    importer = DataImporter()
    preprocessor = DataPreprocessor()
    trainer = ModelTrainer()
    predictor = ModelPredictor()
    evaluator = ModelEvaluator()
    exporter = ResultExporter()
    # Import data
    data = importer.import_data('data.csv')
    # Preprocess data
    processed_data, target = preprocessor.preprocess_data(data)
    # Train model
    model = trainer.train_model(processed_data, target)
    # Predict new instances
    predictions = predictor.predict(processed_data)
    # Evaluate model
    evaluation_results = evaluator.evaluate_model(predictions, target)
    # Export results
    exporter.export_results(evaluation_results, 'results.csv')