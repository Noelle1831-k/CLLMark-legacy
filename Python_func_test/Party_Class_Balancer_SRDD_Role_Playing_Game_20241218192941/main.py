def main():
    '''
    Main function to handle application flow.
    '''
    print("Welcome to the RPG Party Recommender!")
    classes = load_classes()
    if not classes:
        print("No data available. Exiting application.")
        return
    print("\nAvailable Classes:")
    for cls, abilities in classes.items():
        print(f"{cls}: {abilities}")
    print("\nAnalyzing optimal party combinations...")
    recommender = PartyRecommender(classes)
    recommendations = recommender.generate_recommendations()
    print("\nRecommended Party Combinations:")
    for idx, rec in enumerate(recommendations, start=1):
        print(f"Combination {idx}: {rec}")
    print("Thank you for using the RPG Party Recommender!")