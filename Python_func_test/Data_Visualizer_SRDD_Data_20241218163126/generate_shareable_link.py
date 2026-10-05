def generate_shareable_link(visualization):
    '''
    Generates a shareable link for the visualization.
    '''
    unique_id = generate_unique_id()
    link = f"http://datavisualizer.com/view/{unique_id}"
    return link