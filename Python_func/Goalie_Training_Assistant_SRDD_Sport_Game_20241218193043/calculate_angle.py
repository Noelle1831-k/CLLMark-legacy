def calculate_angle(point1, point2):
    '''
    Calculates the angle between two points.
    '''
    return math.degrees(math.atan2(point2['y'] - point1['y'], point2['x'] - point1['x']))