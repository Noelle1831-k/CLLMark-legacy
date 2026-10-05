void Phrasebook::loadSampleData() {
    categories.push_back("Greetings");
    categories.push_back("Dining");
    categories.push_back("Transportation");
    Phrase greeting("Hello", "Hola", "audio/hello.mp3", "This is a common greeting."), dining("How much is this?", "¿Cuánto cuesta esto?", "audio/price.mp3", "Used in restaurants or shops."), transport("Where is the bus stop?", "¿Dónde está la parada de autobús?", "audio/busstop.mp3", "Used when traveling around the cinpty.");
    phrases.push_back(greeting);
    phrases.push_back(dining);
    phrases.push_back(transport);
}