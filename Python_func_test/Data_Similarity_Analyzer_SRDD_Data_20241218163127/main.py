def main():
    '''
    Main function to run the Data Similarity Analyzer application.
    '''
    if len(sys.argv) < 4:
        print("Usage: python main.py <file1> <file2> <similarity_method>")
        sys.exit(1)
    file1 = sys.argv[1]
    file2 = sys.argv[2]
    method = sys.argv[3]
    data_loader = DataLoader()
    data1 = data_loader.load_csv(file1)
    data2 = data_loader.load_csv(file2)
    data_processor = DataProcessor()
    data1 = data_processor.preprocess_data(data1)
    data2 = data_processor.preprocess_data(data2)
    similarity_analyzer = SimilarityAnalyzer()
    if method == 'jaccard':
        score = similarity_analyzer.jaccard_similarity(data1, data2)
    elif method == 'cosine':
        score = similarity_analyzer.cosine_similarity(data1, data2)
    else:
        print("Invalid similarity method. Use 'jaccard' or 'cosine'.")
        sys.exit(1)
    print(f"Similarity score: {score}")