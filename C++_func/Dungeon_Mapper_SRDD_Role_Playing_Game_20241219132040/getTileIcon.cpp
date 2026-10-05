char Tileset::getTileIcon(char type) {
    switch (type) {
        case 'R': return 'R';
        case 'C': return 'C';
        case 'T': return 'T';
        case 'X': return 'X';
        default: return '.';
    }
}