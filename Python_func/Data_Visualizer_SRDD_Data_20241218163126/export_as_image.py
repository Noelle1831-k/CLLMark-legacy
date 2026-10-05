def export_as_image(visualization, file_path):
    '''
    Exports the visualization as an image.
    '''
    if not file_path.endswith('.png'):
        file_path += '.png'
    visualization.figure.savefig(file_path)
    print(f"Visualization exported as {file_path}")