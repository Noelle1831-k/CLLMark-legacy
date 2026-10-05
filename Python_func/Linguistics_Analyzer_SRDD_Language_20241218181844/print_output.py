def print_output(results):
    '''
    Pretty-prints the output of sentence analysis and grammar checking in a readable format.
    '''
    print("\nResults:")
    print(json.dumps(results, indent=4))
    print("\nNote: Results are based on basic grammar and sentence analysis rules.")