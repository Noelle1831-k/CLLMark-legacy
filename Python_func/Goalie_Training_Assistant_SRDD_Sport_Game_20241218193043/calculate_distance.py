def calculate_distance(point1, point2):
    '''
    Calculates the distance between two points.
    '''
    return math.sqrt((point1['x'] - point2['x'])**2 + (point1['y'] - point2['y'])**2)