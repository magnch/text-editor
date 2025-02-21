#include "TextEditor.h"

// Constructs and opens the text editor window 
TextEditor::TextEditor(TDT4102::Point pos) : TDT4102::AnimationWindow{pos.x, pos.y, windowWidth, windowHeight, "Text Editor"},
    loadButton{loadPos, buttonWidth, buttonHeight, "Load text"}, 
    saveButton{savePos, buttonWidth, buttonHeight, "Save text"},
    textBox{textboxPos, textboxWidth, textboxHeight},
    fileTextBox{fileTextboxPos, fileTextboxWidth, fileTextboxHeight}
{
    // Adds GUI elements and sets callbacks
    add(loadButton);
    add(saveButton);
    add(textBox);
    add(fileTextBox);
    loadButton.setCallback(std::bind(&TextEditor::cb_load, this));
    saveButton.setCallback(std::bind(&TextEditor::cb_save, this));
}

// Loads text from file specified in text box
void TextEditor::loadFromFile() {
    storedText = "";
    filename = fileTextBox.getText();
    std::filesystem::path loadPath{filename};
    std::ifstream ifs{loadPath};
    if (!ifs) {
        throw std::ios_base::failure("Error: Could not open load file: " + filename);
    }
    std::string s;
    while(getline(ifs, s)) {
        storedText += s;
    }
    textBox.setText(storedText);
}

// Saves text to file specified in text box
void TextEditor::saveToFile() {
    storedText = textBox.getText();
    filename = fileTextBox.getText();
    std::filesystem::path savePath{filename};
    std::ofstream ofs{savePath};
    if (!ofs) {
        throw std::ios_base::failure("Could not open save file: " + filename);
    }
    ofs << storedText;
}

// Callback funtion for "Load text"-button
void TextEditor::cb_load() {
    try{
        loadFromFile();
    }
    catch(const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Callback function for "Save text"-button
void TextEditor::cb_save() {
    try{
        saveToFile();
    }
    catch(const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}