MainApp(string playerName) {
        player.setName(playerName);
        games.push_back(new MathGame());
        games.push_back(new ScienceGame());
        games.push_back(new LanguageArtsGame());
        games.push_back(new CriticalThinkingGame());
    }