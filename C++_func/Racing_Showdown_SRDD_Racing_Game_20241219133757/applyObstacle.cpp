void RaceTrack::applyObstacle(int &position) {
    for (vector<int>::iterator it = obstacles.begin(); it != obstacles.end(); ++it) {
        if (position == *it) {
            cout << "Hit an obstacle!" << endl;
            position -= 10; 
            break;
        }
    }
}