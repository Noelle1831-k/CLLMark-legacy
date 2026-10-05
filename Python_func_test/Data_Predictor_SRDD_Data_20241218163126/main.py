def main():
    # Initialize components
    importer = DataImporter()
    preprocessor = DataPreprocessor()
    trainer = ModelTrainer()
    # Import data
    data = importer.import_data('data.csv')
    # Preprocess data
    clean_data = preprocessor.clean_data(data)
    encoded_data = preprocessor.encode_data(clean_data)
    # Train model
    model = trainer.train_model(encoded_data, 'target')
    # Initialize Predictor with the trained model
    predictor = Predictor(model)
    # Make predictions
    new_data = importer.import_data('new_data.csv')
    new_data_clean = preprocessor.clean_data(new_data)  # Ensure new data is cleaned
    new_data_encoded = preprocessor.encode_data(new_data_clean)  # Ensure new data is encoded
    predictions = predictor.predict(new_data_encoded)
    print(predictions)