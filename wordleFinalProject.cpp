#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <map>
#include <fstream>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// Color function for terminal output
void lettercolor(int color, int color1) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (color1 << 4) | color);
}

// ===== GUI CENTERING SYSTEM =====
struct TerminalSize {
    int width;
    int height;
};

// Get terminal dimensions
TerminalSize getTerminalSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width = 80, height = 25; // Default fallback
    
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    
    return {width, height};
}

// Center a single line of text
void printCentered(const string& text, int color = 15) {
    TerminalSize term = getTerminalSize();
    int padding = (term.width - text.length()) / 2;
    if (padding < 0) padding = 0;
    
    lettercolor(color, 0);
    cout << string(padding, ' ') << text << endl;
}

// Center multiple lines with optional top padding
void printCenteredBlock(const vector<string>& lines, int topPadding = 0, int color = 15) {
    TerminalSize term = getTerminalSize();
    
    // Add top padding for vertical centering
    for (int i = 0; i < topPadding; i++) {
        cout << endl;
    }
    
    for (const string& line : lines) {
        printCentered(line, color);
    }
}

// Create a centered box with content
void printCenteredBox(const vector<string>& content, const string& title = "", int boxColor = 11, int textColor = 15) {
    TerminalSize term = getTerminalSize();
    
    // Find the longest line to determine box width
    int maxWidth = 0;
    for (const string& line : content) {
        if (line.length() > maxWidth) maxWidth = line.length();
    }
    if (title.length() > maxWidth) maxWidth = title.length();
    
    // Add padding inside the box
    maxWidth += 4;
    
    // Create the box
    vector<string> box;
    
    // Top border
    string topBorder = "+" + string(maxWidth, '-') + "+";
    box.push_back(topBorder);
    
    // Title if provided
    if (!title.empty()) {
        string titleLine = "| " + title + string(maxWidth - title.length() - 1, ' ') + "|";
        box.push_back(titleLine);
        string separator = "+" + string(maxWidth, '-') + "+";
        box.push_back(separator);
    }
    
    // Content lines
    for (const string& line : content) {
        string contentLine = "| " + line + string(maxWidth - line.length() - 1, ' ') + "|";
        box.push_back(contentLine);
    }
    
    // Bottom border
    string bottomBorder = "+" + string(maxWidth, '-') + "+";
    box.push_back(bottomBorder);
    
    // Calculate vertical centering
    int verticalPadding = (getTerminalSize().height - box.size()) / 3;
    if (verticalPadding < 1) verticalPadding = 1;
    
    printCenteredBlock(box, verticalPadding, boxColor);
}

// Clear screen and set optimal terminal size
void initializeGUI() {
    system("cls");
    // Set console to a good size for the game
    system("mode con: cols=120 lines=35");
}

// Create a centered input prompt
string getCenteredInput(const string& prompt, int color = 9) {
    string input;
    printCentered("", 15); // Empty line for spacing
    
    TerminalSize term = getTerminalSize();
    int padding = (term.width - prompt.length() - 20) / 2; // 20 for input space
    if (padding < 0) padding = 0;
    
    lettercolor(color, 0);
    cout << string(padding, ' ') << prompt;
    lettercolor(15, 0);
    getline(cin, input);
    return input;
}

// Create centered menu options
void printCenteredMenu(const vector<string>& options, const string& title = "Menu") {
    vector<string> menuContent;
    
    for (size_t i = 0; i < options.size(); i++) {
        menuContent.push_back(to_string(i + 1) + ") " + options[i]);
    }
    
    printCenteredBox(menuContent, title, 14, 15);
}

// ===== END GUI SYSTEM =====

class Convert{
	private:
		string word;
	public:
		Convert(string inputWord){
   		 word = inputWord;
		}
		void ToLower(){
			for(int i=0; i<5;i++){
			word[i] = tolower(word[i]);
			}
		}
		string getWord(){
		return word;
		}	
	};

string biology()
{
    string words[] = {"virus", "brain", "heart", "plant", "genes", "blood", "fungi", "cilia", "drake",
                      "algae", "teeth", "nerve", "cells", "coral", "yeast", "ovary", "sperm", "spore",
                      "biped", "spine", "tumor", "swarm", "sense", "ferns", "gland", "flora", "fauna",
                      "phage", "mould", "leech", "molar", "sheep", "reefs", "larva", "fetal", "penis",
                      "ankle", "ozone", "stoma", "swine", "perch", "toxin", "cycle", "zebra", "polar",
                      "fiber", "pests", "biome", "fruit", "gonad", "hypha", "model", "phase", "seeds",
                      "feeds", "chick", "shell", "xylem", "acids", "bases", "amine", "salts", "dicot",
                      "genus", "liver", "lymph", "organ", "ovule", "shrub", "anion", "onion", "basal"};
    return words[rand() % 72];
}

map<string, string> HintMap()
{
    map<string, string> wordHintMap;
    wordHintMap["virus"] = "Causes diseases like COVID-19";
    wordHintMap["brain"] = "Organ responsible for thinking";
    wordHintMap["heart"] = "Pumps blood throughout the body";
    wordHintMap["plant"] = "Produces oxygen through photosynthesis";
    wordHintMap["genes"] = "Carry genetic information";
    wordHintMap["blood"] = "Red liquid flowing in our veins";
    wordHintMap["fungi"] = "Microscopic organisms like mushrooms";
    wordHintMap["algae"] = "Photosynthetic organisms in water";
    wordHintMap["teeth"] = "Used for biting and chewing";
    wordHintMap["nerve"] = "Transmits signals in the body's nervous system";
    wordHintMap["cells"] = "Basic unit of life";
    wordHintMap["coral"] = "Marine invertebrates, form reefs";
    wordHintMap["yeast"] = "Single-celled fungus";
    wordHintMap["ovary"] = "Female reproductive organ";
    wordHintMap["sperm"] = "Male reproductive cell";
    wordHintMap["spore"] = "Reproductive cell of fungi";
    wordHintMap["biped"] = "Animal with two legs";
    wordHintMap["spine"] = "Backbone";
    wordHintMap["tumor"] = "Abnormal tissue growth";
    wordHintMap["swarm"] = "Group of flying insects";
    wordHintMap["sense"] = "Perception through sensory organs";
    wordHintMap["ferns"] = "Non-flowering vascular plants";
    wordHintMap["gland"] = "Secretory organ";
    wordHintMap["flora"] = "Plant life of a region";
    wordHintMap["fauna"] = "Animal life of a region";
    wordHintMap["cilia"] = "Tiny hair-like structures";
    wordHintMap["phage"] = "Virus that infects bacteria";
    wordHintMap["mould"] = "Fungal growth";
    wordHintMap["leech"] = "Blood-sucking worm";
    wordHintMap["molar"] = "Tooth for grinding";
    wordHintMap["sheep"] = "Domesticated ruminant mammal";
    wordHintMap["reefs"] = "Ridge of coral in the sea";
    wordHintMap["larva"] = "Immature form of insect";
    wordHintMap["fetal"] = "Relating to unborn offspring";
    wordHintMap["ankle"] = "Joint between foot and leg";
    wordHintMap["ozone"] = "Atmospheric gas";
    wordHintMap["stoma"] = "Pore in plant leaf";
    wordHintMap["swine"] = "Pig";
    wordHintMap["perch"] = "Fish or a place to sit";
    wordHintMap["toxin"] = "Poison";
    wordHintMap["cycle"] = "Repeating sequence";
    wordHintMap["zebra"] = "Striped African mammal";
    wordHintMap["polar"] = "Relating to the North or South Pole";
    wordHintMap["fiber"] = "Thread-like structure";
    wordHintMap["pests"] = "Unwanted organisms";
    wordHintMap["biome"] = "major ecological community with distinct climate and flora";
    wordHintMap["fruit"] = "the ripened reproductive body of a seed plant";
    wordHintMap["gonad"] = "a gland in which gametes (sex cells) are produced";
    wordHintMap["hypha"] = "any of the threadlike filaments forming the mycelium of a fungus";
    wordHintMap["model"] = "a representation of something, often on a smaller scale";
    wordHintMap["phase"] = "any distinct time period in a sequence of events";
    wordHintMap["seeds"] = "small, hard part of a plant from which a new plant can grow";
    wordHintMap["feeds"] = "Food for animals";
    wordHintMap["chick"] = "Immature growth stage of chicken";
    wordHintMap["shell"] = "the outer covering of an animal";
    wordHintMap["xylem"] = "plant tissue that conducts water and dissolved nutrients";
    wordHintMap["acids"] = "Oppsite of bases";
    wordHintMap["bases"] = "Opposite of acids";
    wordHintMap["amine"] = "contain a basic nitrogen atom with a lone pair";
    wordHintMap["salts"] = "formed from the reaction of an acid with a base";
    wordHintMap["dicot"] = "two cotyledons";
    wordHintMap["genus"] = "group of species that are closely related through common decent";
    wordHintMap["liver"] = "Organ with the role of detoxifying blood";
    wordHintMap["lymph"] = "fluid which travels throughout the lymphatic system in animals";
    wordHintMap["organ"] = "group of tissues that performs a specific function in the body";
    wordHintMap["ovule"] = "part of the makeup of the female reproductive organ in seed plants";
    wordHintMap["shrub"] = "woody plant that is typically less than 8 meters tall";
    wordHintMap["anion"] = "atom with negative charge";
    wordHintMap["onion"] = "make you cry";
    wordHintMap["basal"] = "Relating to the base or foundation of something";
    wordHintMap["penis"] = "Male reproductive organ";
    wordHintMap["drake"] = "Male duck";

    return wordHintMap;
}
int main()
{
    initializeGUI();
    system("Color 0F");  // Clean white on black theme
    srand(time(0));
    string name;
    string gender;
    int score = 0;
    bool module1completed = false;
    bool hasPlayedgame = false;
    
    // Welcome Screen with centered ASCII art
    vector<string> welcomeArt = {
        " ___       __   _______   ___       ________  ________  _____ ______   _______   ___",
        "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\ |\\  \\",
        "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|\\ \\  \\",
        " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/_\\ \\  \\",
        "  \\ \\  \\|__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \\__\\",
        "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\|__|",
        "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|   ___",
        "                                                                                      |\\__\\",
        "                                                                                      \\|__|",
        "",
        "                              Welcome to Biology Wordle!"
    };
    
    printCenteredBlock(welcomeArt, 3, 11);
    
    name = getCenteredInput("Please enter your name: ", 14);
    
    do
    {
        gender = getCenteredInput("Please enter your gender (M/F): ", 14);
        if (gender == "m" || gender == "M")
        {
            gender = "Mr.";
        }
        else if (gender == "f" || gender == "F")
        {
            gender = "Mrs.";
        }
        else
        {
            printCentered("Invalid gender", 12);
            printCentered("Please enter 'M' for Male or 'F' for Female.", 12);
        }
    } while (gender != "Mr." && gender != "Mrs.");
    initializeGUI();
    bool exitprogram = false;
    do
    {
        system("Color 0F");
        
        // Create centered menu
        vector<string> menuOptions = {
            "Let's Play Biology Wordle",
            "Check Score List",
            "Biology Wordle Developer Info",
            "Exit Program"
        };
        
        printCenteredMenu(menuOptions, "Main Menu - Welcome " + gender + name);
        
        string choice = getCenteredInput("Please select a module (1-4): ", 14);
        int num = 0;
        try {
            num = stoi(choice);
        } catch (...) {
            printCentered("Invalid input! Please enter a number between 1-4.", 12);
            system("pause");
            continue;
        }
        
        initializeGUI();
        switch (num)
        {
        case 1:
        {
            system("Color 0F");
            module1completed = true;
            
            // Module 1 Welcome with centered layout
            vector<string> gameTitle = {
                " _      ______ _______ _____    _____  _           __     __  __          ______  _____  _____  _      ______ ",
                "| |    |  ____|__   __/ ____|  |  __ \\| |        /\\\\ \\   / /  \\ \\        / / __ \\|  __ \\|  __ \\| |    |  ____|",
                "| |    | |__     | | | (___    | |__) | |       /  \\\\ \\_/ /    \\ \\  /\\  / / |  | | |__) | |  | | |    | |__   ",
                "| |    |  __|    | |  \\___ \\   |  ___/| |      / /\\ \\\\   /      \\ \\/  \\/ /| |  | |  _  /| |  | | |    |  __|  ",
                "| |____| |____   | |  ____) |  | |    | |____ / ____ \\| |        \\  /\\  / | |__| | | \\ \\| |__| | |____| |____ ",
                "|______|______|  |_| |_____/   |_|    |______/_/    \\_\\_|         \\/  \\/   \\____/|_|  \\_\\_____/|______|______|",
                "",
                "                              Biology Wordle Game"
            };
            
            printCenteredBlock(gameTitle, 2, 11);
            
            // Game rules in a centered box
            vector<string> rules = {
                "Here are the rules:",
                "",
                "> There are 10 words in this game",
                "> For each word, you are given five attempts to guess",
                "> You may type in any characters (uppercase or lowercase)",
                "> Type 'SKIP' to skip a word and see the answer (no points)",
                "> After each guess, we provide feedback on each letter",
                "> For each correct answer, you will be awarded 10 points"
            };
            
            printCenteredBox(rules, "Game Rules", 14, 15);
            
            printCentered("", 15);
            printCentered("Press any key to start the game...", 10);
            system("pause");
            initializeGUI();
            char letter;
            string target;
            map<string, string> Hint = HintMap();
            string guess;
            int limitguess = 0;
            int Max_Played = 0;
            vector<string> skippedWords;  // Track skipped words
            vector<string> skippedHints;  // Track hints for skipped words
            
            cout << "This is Biology Word 1 until 10" << endl;

            while (Max_Played < 10)
            {	
            	system("Color 09");
                target = biology();
                limitguess = 0;
                
                cout << "This is Word " << Max_Played + 1 << " of 10" << endl;
                lettercolor(4, 0);
                cout << "Hint: " << Hint[target] << endl;
                cout << " _____________________________" << endl;
                cout << "|     |     |     |     |     |" << endl;
                cout << "|     |     |     |     |     |" << endl;
                cout << "|_____|_____|_____|_____|_____|" << endl;
                do
                {
                    if (limitguess < 5){
                    	 lettercolor(9, 0);
                    	 cout << "\nAttempt " << (limitguess + 1) << " of 5" << endl;
                    	 lettercolor(13, 0);
                    	 cout << "(Type 'SKIP' to skip this word and see the answer)" << endl;
                        lettercolor(9, 0);
                        cout << "Enter your guess: ";
                        cin >> guess;
                        
                        // Check if user wants to skip
                        Convert skipCheck(guess);
                        skipCheck.ToLower();
                        if (skipCheck.getWord() == "skip") {
                            lettercolor(14, 0);
                            cout << "\nYou chose to skip this word." << endl;
                            cout << "The correct word was: " << target << endl;
                            lettercolor(4, 0);
                            cout << "Definition: " << Hint[target] << endl;
                            
                            // Store skipped word for summary
                            skippedWords.push_back(target);
                            skippedHints.push_back(Hint[target]);
                            
                            lettercolor(13, 0);
                            cout << "Moving to the next word..." << endl;
                            break;  // Exit the guess loop to move to next word
                        }
                        
                        if (guess.length() != 5)
                        {
                            cout << "Please only input 5 letters word or type 'SKIP' to skip" << endl;
                            continue;
                        }
                        cout << "For your guess: " << endl;
                        cout << " _____________________________" << endl;
                        cout << "|     |     |     |     |     |" << endl;
                        cout << "|  " << guess[0] << "  |  " << guess[1] << "  |  " << guess[2] << "  |  " << guess[3] << "  |  " << guess[4] << "  |" << endl;
                        cout << "|_____|_____|_____|_____|_____|" << endl;
                        Convert convert(guess);
                        convert.ToLower();
                        guess = convert.getWord();
                        for (int i = 0; i < 5; i++)
                        {	
							Beep(1000, 250);
                            letter = guess[i];
                            if (target.find(letter) != string::npos)
                            {
                                if (target[i] == letter)
                            	{
                            		 lettercolor(10, 0);
                                    cout << letter << " <  is inside Word and its in the right position" << endl;
                                }
                                else
                                {	
                                	 lettercolor(14, 0);
                                    cout << letter << " <  is inside Word, but its in the wrong position" << endl;
                                }
                            }
                            else
                            {
                            	 lettercolor(12, 0);
                                cout << letter << " <  is not inside Word" << endl;
                            }
                        }

                        if (guess == target)
                        {
                        	lettercolor(11, 0);
                            cout << "Congratulations! You have guessed Word right!" << endl;
                            score = score + 10;
                            cout << "Total score: " << score << endl;
                            break;
                        }
                        else
                        {
                            limitguess++;
                        }
                    }
                    else
                    {
                        lettercolor(12, 0);
                        cout << "Sorry! You used all 5 attempts for this word!" << endl;
                        lettercolor(14, 0);
                        cout << "The correct word was: " << target << endl;
                        
                        // Give user choice to continue with same word or move to next
                        char userChoice;
                        do {
                            lettercolor(9, 0);
                            cout << "\nWould you like to:" << endl;
                            cout << "C - Continue trying this word (reset attempts)" << endl;
                            cout << "N - Move to the Next word" << endl;
                            cout << "Enter your choice (C/N): ";
                            cin >> userChoice;
                            
                            if (userChoice == 'C' || userChoice == 'c') {
                                limitguess = 0;  // Reset attempts for same word
                                lettercolor(11, 0);
                                cout << "Great! You can try this word again!" << endl;
                                system("pause");
                                system("cls");
                                system("Color 09");
                                cout << "Word: " << Max_Played + 1 << " of 10" << endl;
                                lettercolor(4, 0);
                                cout << "Hint: " << Hint[target] << endl;
                                cout << " _____________________________" << endl;
                                cout << "|     |     |     |     |     |" << endl;
                                cout << "|     |     |     |     |     |" << endl;
                                cout << "|_____|_____|_____|_____|_____|" << endl;
                                break;
                            } else if (userChoice == 'N' || userChoice == 'n') {
                                lettercolor(13, 0);
                                cout << "Moving to the next word..." << endl;
                                break;
                            } else {
                                lettercolor(12, 0);
                                cout << "Invalid choice! Please enter 'C' to continue or 'N' for next word." << endl;
                            }
                        } while (true);
                        
                        if (userChoice == 'N' || userChoice == 'n') {
                            break;  // Exit the guess loop to move to next word
                        }
                    }
                } while (limitguess < 5);
                system("pause");
                system("cls");
				system("Color F2");
                Max_Played++;
                if (Max_Played >= 10) {
                hasPlayedgame = true;
                
                // Save score to file immediately after completing 10 games
                ofstream outputFile("ScoreList.txt", ios::app);
                if (outputFile.is_open())
                {
                    outputFile << " " << name << "              " << score << endl;
                    outputFile.close();
                    cout << "Score has been successfully saved to 'ScoreList.txt'." << endl;
                }
                else
                {
                    cout << "Error: Unable to save score to file." << endl;
                }
                
	            int choice;
	            cout << "You have played 10 games." << endl;
	            cout << "Total score: " << score << endl;
	            
	            // Display summary of skipped words
	            if (!skippedWords.empty()) {
	                lettercolor(14, 0);
	                cout << "\n=== SKIPPED WORDS SUMMARY ===" << endl;
	                lettercolor(9, 0);
	                cout << "You skipped " << skippedWords.size() << " word(s):" << endl;
	                for (size_t i = 0; i < skippedWords.size(); i++) {
	                    lettercolor(13, 0);
	                    cout << (i + 1) << ". " << skippedWords[i] << " - " << skippedHints[i] << endl;
	                }
	                lettercolor(11, 0);
	                cout << "Review these words to improve your biology knowledge!" << endl;
	            }
	            
	            cout << "Your name and score have been added into the ScoreList.txt file." << endl;
	            cout << "Press 1 to repeat the Wordle Game, Press 2 to go back to Selection Menu" << endl;
	            cin >> choice;
	            while (choice != 1 && choice != 2) {
	                cout << "Please enter '1' to repeat the Wordle Game or '2' to go back to Selection Menu: ";
	                cin >> choice;
	            }
	            if (choice == 1) {
	                Max_Played = 0;
	                score = 0;
	                skippedWords.clear();  // Reset skipped words
	                skippedHints.clear();  // Reset skipped hints
	                system ("cls");
	            } else if (choice == 2) {
	                break;
	            }
	        }
            }
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {	system("Color F5");
            cout << R"(
                                                                 
 _ _ _           _ _        _____                    _ _     _   
| | | |___ ___ _| | |___   |   __|___ ___ ___ ___   | |_|___| |_ 
| | | | . |  _| . | | -_|  |__   |  _| . |  _| -_|  | | |_ -|  _|
|_____|___|_| |___|_|___|  |_____|___|___|_| |___|  |_|_|___|_|  
                                                                 
)" << '\n';
            
            cout << "Welcome to Module 2: Check Score List, " << name << endl;
            cout << "Here is score list: " << endl;
            
            ifstream scoreFile("ScoreList.txt", ios::in);
            if (scoreFile.is_open()) {
                string line;
                cout << "User Name              Score" << endl;
                cout << "============================" << endl;
                while (getline(scoreFile, line)) {
                    cout << line << endl;
                }
                scoreFile.close();
            } else {
                cout << "Error: Unable to open the score file." << endl;
            }
            
			system("pause");
            system("cls");
            break;
        }
        case 3:
        {	system("Color F6");
            cout << R"(
	    __                     __                              __         ___        
	.--|  |.-----.--.--.-----.|  |.-----.-----.-----.----.    |__|.-----.'  _|.-----.
	|  _  ||  -__|  |  |  -__||  ||  _  |  _  |  -__|   _|    |  ||     |   _||  _  |
	|_____||_____|\___/|_____||__||_____|   __|_____|__|      |__||__|__|__|  |_____|
	                                    |__|                                         
)" << '\n';
            cout << "Welcome to Module3: Biology Wordle Developer Information, " << name << endl;
            cout << "Team Member              StudentID                      Task/ Job Description" << endl;
            cout << "================================================================================================" << endl;
            cout << "Dy Daly                  p20230011         Write the Module 1 and assit in Module 2" << endl;
            cout << "Samreth Rangsey          p20230037         Create and Intergrate Selection menu and fix module 1" << endl;
            cout << "Chheng Rayuth            p20230001         Write Module 2 and Design Module 3" << endl;
            cout << "Kaeu Topin               p20230032         Testing the program and Design the program" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {	system("Color F3");
            char exit;
            do
            {
                if (module1completed)
                {
                    cout << "Are you sure you want to exit the program, " << gender << name << endl;
                }
                else
                {
                    cout << "Are you sure you want to exit before playing Biology Wordle, " << gender << name << endl;
                }
                cout << "Y : Yes" << endl;
                cout << "N : No" << endl;
                cout << "Please enter your answer : ";
                cin >> exit;
                if (exit == 'Y' || exit == 'y')
				{
  					  if (module1completed)
    					{
      					  cout << "Thank you " << gender << name << " for playing Biology Wordle!" << endl;
   						 }
   					system("pause");
    				exitprogram = true;
    				break;
				}
                else if (exit == 'N' || exit == 'n')
                {
                    break;
                }
                else
                {
                    cout << "Please answer with 'Y' or 'N'." << endl;
                }
            } while (true);
            system("cls");
            break;
        }
        }
    } while (!exitprogram);
    return 0;
}
