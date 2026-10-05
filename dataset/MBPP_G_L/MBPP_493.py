def calculate_polygons(startx, starty, endx, endy, radius):
    hexagons = []
    row_offset = 0
    dx = 3 * radius / 2
    dy = math.sqrt(3) * radius
    for y in range(starty, endy):
        for x in range(startx, endx):
            cx = x * dx + row_offset
            cy = y * dy
            hexagon = []
            for i in range(6):
                angle = math.pi / 3 * i
                px = cx + radius * math.cos(angle)
                py = cy + radius * math.sin(angle)
                hexagon.append((px, py))
            hexagon.append(hexagon[0])
            hexagons.append(hexagon)
        row_offset = 0 if row_offset else dx / 2
    return hexagons