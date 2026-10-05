def run_application():
    '''
    Manages the flow of the application.
    '''
    ui = UserInterface()
    sf = SynonymFinder()
    utils = Utilities()
    while True:
        word = ui.get_user_input()
        synonyms = sf.fetch_synonyms(word)
        definitions = sf.get_definition(word)
        examples = sf.get_example_sentences(word)
        formatted_output = utils.format_output({
            'synonyms': synonyms,
            'definitions': definitions,
            'examples': examples
        })
        ui.display_results(formatted_output)
        if not ui.prompt_continue():
            break