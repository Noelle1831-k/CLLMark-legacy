def __init__(self, connected_roads):
        '''
        Initialize an intersection with connected roads and default traffic signals.
        '''
        self.connected_roads = connected_roads
        self.signals = {road: 'red' for road in connected_roads}
        self.traffic_data = {road: 0 for road in connected_roads}  # Stores traffic density