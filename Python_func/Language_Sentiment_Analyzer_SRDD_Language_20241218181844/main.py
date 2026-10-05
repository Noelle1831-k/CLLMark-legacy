def main():
    # Load configuration
    with open('config.json', 'r') as config_file:
        config = json.load(config_file)
    # Load lexicon
    lexicon = load_lexicon(config['lexicon_path'])
    # Initialize sentiment model
    model = SentimentModel(lexicon)
    # Sample text for analysis
    sample_text = "I love this product! It's absolutely wonderful."
    # Preprocess text
    processed_text = preprocess_text(sample_text)
    # Analyze sentiment
    sentiment = model.analyze_sentiment(processed_text)
    # Output result
    print(f"Sentiment: {sentiment}")