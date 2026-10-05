int main(int argc, char *argv[]) {
    Translator translator;
    FileManager fileManager;
    fileManager.readFile("dictionary.txt", translator);
    string text1 = "Hello";
    string translatedText1 = translator.translate(text1, "English", "Spanish");
    cout << "Translated Text (English to Spanish): " << translatedText1 << endl;
    string text2 = "Hola";
    string translatedText2 = translator.translate(text2, "Spanish", "English");
    cout << "Translated Text (Spanish to English): " << translatedText2 << endl;
    string text3 = "Bonjour";
    string translatedText3 = translator.translate(text3, "French", "English");
    cout << "Translated Text (French to English): " << translatedText3 << endl;
    return 0;
}