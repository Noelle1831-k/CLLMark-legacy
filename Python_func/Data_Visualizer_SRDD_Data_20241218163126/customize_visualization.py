def customize_visualization(visualization, options):
    '''
    Customizes the appearance of a visualization.
    '''
    # Assume options is a dictionary with customization parameters
    if 'title' in options:
        visualization.figure.suptitle(options['title'])
    if 'xlabel' in options:
        visualization.figure.axes[0].set_xlabel(options['xlabel'])
    if 'ylabel' in options:
        visualization.figure.axes[0].set_ylabel(options['ylabel'])
    if 'color' in options:
        for bar in visualization.figure.axes[0].patches:
            bar.set_color(options['color'])