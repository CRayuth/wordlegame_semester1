# 🧬 Biology Wordle

A sophisticated console-based word guessing game focused on biology terminology, featuring an elegant Apple-style GUI interface and comprehensive gameplay mechanics.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Screenshots](#screenshots)
- [Installation](#installation)
- [Usage](#usage)
- [Gameplay](#gameplay)
- [Technical Specifications](#technical-specifications)
- [Project Structure](#project-structure)
- [Development Team](#development-team)
- [Contributing](#contributing)
- [License](#license)

## 🌟 Overview

Biology Wordle is an educational word guessing game designed to help students learn biology terminology in an engaging and interactive way. The game challenges players to guess 5-letter biology-related words within a limited number of attempts, providing immediate feedback and educational value through hints and definitions.

### Key Highlights
- **Educational Focus**: Curated collection of 72 biology terms
- **Professional GUI**: Apple-style centered interface design
- **Flexible Gameplay**: Skip functionality and retry options
- **Score Tracking**: Persistent scoring system with file storage
- **Cross-Platform**: Compatible with Windows systems

## ✨ Features

### 🎮 Core Gameplay
- **10-Word Challenge**: Complete rounds of 10 carefully selected biology words
- **5-Attempt System**: Up to 5 guesses per word with intelligent feedback
- **Smart Feedback**: Color-coded letter position and inclusion indicators
- **Skip Functionality**: Option to skip difficult words and view answers
- **Retry Mechanism**: Continue trying the same word or move to the next

### 🎨 User Interface
- **Centered GUI Design**: Professional Apple-style interface
- **Dynamic Terminal Sizing**: Automatic optimal terminal configuration
- **Color-Coded Feedback**: Visual indicators for game state and feedback
- **Responsive Layout**: Adapts to different terminal sizes
- **Clean Typography**: Elegant ASCII art and consistent formatting

### 📊 Scoring & Tracking
- **Point System**: 10 points per correctly guessed word
- **Persistent Storage**: Scores saved to `ScoreList.txt`
- **Skipped Words Summary**: Review of missed words with definitions
- **Progress Tracking**: Real-time score updates and game progression

### 🛠️ Advanced Features
- **Case Insensitive Input**: Accepts both uppercase and lowercase
- **Input Validation**: Robust error handling and user guidance
- **Multiple Modules**: Game, score viewing, and developer information
- **Exit Confirmation**: Smart exit prompts based on game completion status

## 🖼️ Screenshots

```
                              +------------------------------------------+
                              | Main Menu - Welcome Mr.John            |
                              +------------------------------------------+
                              | 1) Let's Play Biology Wordle           |
                              | 2) Check Score List                     |
                              | 3) Biology Wordle Developer Info        |
                              | 4) Exit Program                         |
                              +------------------------------------------+
```

*Example of the centered menu interface*

## 🚀 Installation

### Prerequisites
- Windows operating system
- C++ compiler (GCC recommended)
- Terminal/Command Prompt access

### Quick Start
1. **Clone or Download** the project files
2. **Compile** the source code:
   ```bash
   g++ wordleFinalProject.cpp -o wordleFinalProject
   ```
3. **Run** the executable:
   ```bash
   ./wordleFinalProject
   ```

### System Requirements
- **OS**: Windows 7/8/10/11
- **RAM**: 4MB minimum
- **Storage**: 1MB free space
- **Terminal**: Support for ANSI color codes

## 📖 Usage

### Starting the Game
1. Launch the executable
2. Enter your name when prompted
3. Select your gender (M/F)
4. Choose from the main menu options

### Menu Options
- **Module 1**: Play the Biology Wordle game
- **Module 2**: View score leaderboard
- **Module 3**: Developer team information
- **Module 4**: Exit the program

## 🎯 Gameplay

### How to Play
1. **Word Selection**: The game randomly selects a 5-letter biology term
2. **Hint Display**: A descriptive hint is provided for each word
3. **Guessing**: Enter your 5-letter guess or type 'SKIP' to skip
4. **Feedback**: Receive color-coded feedback on letter positions
5. **Scoring**: Earn 10 points for each correct guess

### Feedback System
- 🟢 **Green**: Letter is correct and in the right position
- 🟡 **Yellow**: Letter is in the word but wrong position
- 🔴 **Red**: Letter is not in the word

### Special Commands
- **SKIP**: Skip current word and view the answer
- **Continue/Next**: After 5 failed attempts, choose to retry or continue

### Word Categories
The game includes biology terms from various categories:
- Anatomy & Physiology
- Cell Biology
- Ecology
- Genetics
- Microbiology
- Plant Biology
- Zoology

## 🔧 Technical Specifications

### Architecture
- **Language**: C++
- **Paradigm**: Object-oriented programming
- **GUI System**: Custom terminal-based interface
- **File I/O**: Text-based score persistence

### Key Components
- **Convert Class**: Handles case conversion for user input
- **GUI System**: Comprehensive centering and layout functions
- **Word Database**: Curated biology terminology with hints
- **Score Manager**: File-based scoring system

### Performance
- **Memory Usage**: ~2MB runtime
- **Startup Time**: <1 second
- **File Size**: ~340KB executable

## 📁 Project Structure

```
semester1_project/
├── wordleFinalProject.cpp    # Main source code
├── wordleFinalProject.exe    # Compiled executable
├── ScoreList.txt            # Score storage file
└── README.md               # Project documentation
```

### Core Functions
- `biology()`: Random word selection
- `HintMap()`: Word-hint mapping system
- `printCenteredBox()`: GUI layout management
- `lettercolor()`: Terminal color control

## 👥 Development Team

| Name | Student ID | Role | Responsibilities |
|------|------------|------|------------------|
| **Dy Daly** | p20230011 | Lead Developer | Module 1 development, Module 2 assistance |
| **Samreth Rangsey** | p20230037 | Systems Integrator | Menu system, Module 1 integration |
| **Chheng Rayuth** | p20230001 | Backend Developer | Module 2 development, Module 3 design |
| **Kaeu Topin** | p20230032 | QA Engineer | Testing, program design, UI/UX |

## 🤝 Contributing

We welcome contributions to improve Biology Wordle! Here's how you can help:

### Areas for Contribution
- 🆕 Additional biology terms and categories
- 🎨 Enhanced visual design elements
- 🔧 Performance optimizations
- 🐛 Bug fixes and improvements
- 📚 Documentation updates

### Development Guidelines
1. Follow existing code style and conventions
2. Test thoroughly before submitting changes
3. Update documentation for new features
4. Ensure cross-platform compatibility

## 📄 License

This project is developed as part of an educational assignment. All rights reserved by the development team.

---

*Last updated: September 2025*