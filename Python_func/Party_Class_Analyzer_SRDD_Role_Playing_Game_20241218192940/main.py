def main():
    '''
    Initializes the application and handles user input.
    '''
    if len(sys.argv) < 2:
        print("Usage: python main.py <classes_file>")
        sys.exit(1)
    classes_file = sys.argv[1]
    character_classes = load_classes_from_file(classes_file)
    analyzer = ClassAnalyzer(character_classes)
    analyzer.analyze_combinations()
    best_combination = analyzer.suggest_best_combination()
    print("Best class combination:")
    for cls in best_combination:
        print(cls)