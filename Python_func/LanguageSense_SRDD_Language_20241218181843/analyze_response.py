def analyze_response(response, exercise):
    # Analyze user response against expected answer
    processed_response = LanguageProcessor('English').process(response)
    return {'correct': processed_response == 'hello, world!'}