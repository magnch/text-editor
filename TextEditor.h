#pragma once
#include <fstream>
#include <iostream>
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"


class TextEditor : public TDT4102::AnimationWindow {
    private:
        // Constants defining GUI element sizes
        static constexpr int textboxHeight = 400;
        static constexpr int textboxWidth = 300;
        static constexpr int padSize = 10;
        static constexpr int fileTextboxHeight = 30;
        static constexpr int fileTextboxWidth = textboxWidth;
        static constexpr int buttonHeight = 50;
        static constexpr int buttonWidth = 100;

        static constexpr int windowHeight = 3*padSize + textboxHeight + fileTextboxHeight;
        static constexpr int windowWidth = 3*padSize + textboxWidth + buttonWidth;

        static constexpr TDT4102::Point loadPos = {2*padSize + textboxWidth, padSize};
        static constexpr TDT4102::Point savePos =  {2*padSize + textboxWidth, 2*padSize + buttonHeight};
        static constexpr TDT4102::Point textboxPos = {padSize, padSize};
        static constexpr TDT4102::Point fileTextboxPos = {padSize, 2*padSize + textboxHeight};

        // Buttons
        TDT4102::Button loadButton;
        TDT4102::Button saveButton;

        // Text inputs
        TDT4102::TextInput textBox;
        TDT4102::TextInput fileTextBox;

        // Variables to store filename and text
        std::string filename;
        std::string storedText;

        // File handling
        void loadFromFile();
        void saveToFile();

        // Callback functions
        void cb_load();
        void cb_save();

    
    public:
        // Constructor
        TextEditor(TDT4102::Point pos);
};