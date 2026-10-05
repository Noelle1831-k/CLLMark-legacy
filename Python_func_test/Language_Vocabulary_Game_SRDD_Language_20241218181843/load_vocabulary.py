def load_vocabulary(language):
    print(f"Loading vocabulary for {language}...")
    vocabulary_data = {
        "English": ["apple", "banana", "cherry", "date", "elderberry"],
        "Spanish": ["manzana", "plátano", "cereza", "dátil", "bayas"],
        "French": ["pomme", "banane", "cerise", "datte", "baie"],
        "German": ["Apfel", "Banane", "Kirsche", "Dattel", "Beere"]
    }
    return vocabulary_data.get(language, [])