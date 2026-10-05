void Goalie::reactToShot(const Shot& shot) {
    double reactionDifficulty = shot.getSpeed() / 100.0 + fabs(shot.getAngle() - (positionX + positionY) % 360) / 360.0;
    reactionTime = reactionDifficulty > 1.0 ? 1.0 : reactionDifficulty;
    cout << "Goalie reacts to shot with reaction time: " << reactionTime << " seconds" << endl;
}