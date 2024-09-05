#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>
#include <atomic>

using namespace std;

string playerName; // Global variable to store the player's name
atomic<bool> quitGame(false); // Atomic flag to signal game exit


// Function to clear the screen
void clearScreen() {
    system("clear"); // For Linux
    
}

void waitForEnter() {
  cout << "\nPress Enter to continue..." << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Waits for Enter
}

// Function to display the game's greeting and rules
void displayIntro() {

    cout << "Welcome to Dungeoneer's Odyssey!" << endl;
    cout << "\nWorth Goal: 300" << endl;
    cout << "\nIf your Worth reaches 0, you lose." << endl;
    cout << endl;

    cout << "\nCharacter name: ";
    getline(cin, playerName); // Read the player's name and store it in the global variable
    cout << endl;

    clearScreen();
    // Multi-line string for ASCII art
    string mountainArt =
        "            .          .           .     .                .       .\n"
        "  .      .      *           .       .          .                       .\n"
        "                 .       .   . *                                \n"
        "  .       ____     .      . .            .                           \n"
        "         >>         .        .               .\n"
        " .   .  /WWWI; \\  .       .    .  ____               .         .     .         \n"
        "  *    /WWWWII; \\=====;    .     /WI;:. \\     .        /\\_             .\n"
        "  .   /WWWWWII;..      \\_  . ___/WI;:. \\____ .   .  /MMI: \\    .   .         .\n"
        "     /WWWWWIIIIi;..      \\__/WWWIIII:.. \\____ .   .  /MMWII;   \\    .  .     .\n"
        " . _/WWWWWIIIi;;;:...:   ;\\WWWWWWIIIII;.     \\     /MMWIIII;   \\              .\n"
        "  /WWWWWIWIiii;;;.:.. :   ;\\WWWWWIII;;;::     \\___/MMWIIIII;:   \\___     *\n"
        " /WWWWWIIIIiii;;::.... :   ;|WWWWWWII;;::.:      :;IMWIIIIII;:   \\    .  .     .\n"
        "WWWWWWWWWIIIIIWIIii;;::;..;\\WWWWWWIII;;;:::...    ;IMWIIIII;;     ::  \\     .\n"
        "WWWWWWWWWIIIIIIIIIii;;::.;..;\\WWWWWWWWIIIII;;..  :;IMWIIII;:::     :    \\   \n"
        "WWWWWWWWWWWWWIIIIIIii;;::..;..;\\WWWWWWWWIIII;::; :::::::::.....::       \\\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXX\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXXXXX\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXXXXXXXX\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXXXXXXXXXXXX\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXXXXXXXXXXXXXXX\n"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%XXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << mountainArt << endl;

    cin.get();


    cout << "Your story begins outside of the town of Valungraud." << endl;
    cout << "A small fishing town surrounded by mountainous terrain, thieving bandits, and more." << endl;
    cout << endl;

    cout << "As you wake up on the edge of the riverbed, with your head pounding -" << endl;
    cout << "you look around for anything that is familiar to you... But nothing is." << endl;
    cout << endl;

    cout << "You try to sit up, but notice your vision blurs every time you attempt. You're out of it." << endl;
    cout << "``Well look who's alive?`` a voice from behind you says, lurching your head back just to be reminded of the pain." << endl;
    cout << endl;

    cout << "Before you can gather your thoughts, a mysterious figure steps into your field of view." << endl;
    cout << "They wear a tattered cloak and seem to radiate an otherworldly aura." << endl;
    cout << endl;

    cout << "``You were in a perilous state when I found you, my friend," << endl;
    cout << "and I saved you from certain doom. However, in this realm, everything comes at a price," << endl;
    cout << "and I sense a unique opportunity within you. To leave this place, you must prove your worth.``" << endl;
    cout << endl;

    cout << "The figure's words hang in the air, filled with both mystery and urgency." << endl;
    cout << "You have many questions, but before you can ask, they continue." << endl;
    cout << endl;

    cout << "``You will start with hardly any Worth, for you are close to nothing now, it seems." << endl;
    cout << "When the time comes of you losing all of your worth," << endl;
    cout << "well, I won't be too surprised. I just hope you have more in you than that." << endl;
    cout << endl;

    cout << "If you can prove to me that you were worth my time, you will be freed from this land" << endl;
    cout << "and go back to where you came from." << endl;
    cout << endl;

    cout << "Good luck, for you'll need it." << endl;
    cout << "Now, let your adventure begin, " << playerName << "!``" << endl;

    cout << "Press Enter to start...";
    cin.ignore();

}

int dungeonAdventure(int currentScore) {
    int dungeonScore = currentScore;

    while (true) {
        clearScreen();
        cout << "You have entered the dungeon. It looks very dark and ominous." << endl;
        cout << "\n1. Explore deeper into the dungeon" << endl;
        cout << "\n2. Turn back and exit the dungeon" << endl;
        cout << "\nYour current dungeon score: " << dungeonScore << endl;

        string choice;
        cin >> choice;
        cin.ignore();

        if (choice == "1") {
            int dungeonOutcome = rand() % 8; // Generate a random number for dungeon outcomes

            if (dungeonOutcome == 0) {
                cout << "\nYou encountered a dangerous mega-centipede and barely escaped with scratches. [-30]" << endl;
                dungeonScore -= 30;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (dungeonOutcome == 1) {
                cout << "\nYou found a hidden treasure chest in the dark corners of the dungeon! [+30]" << endl;
                dungeonScore += 30;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (dungeonOutcome == 2) {
                cout << "\nYou see a shiny object poking out of the stone. (1.Inspect, 2.Walk Past)" << endl;
                string shinyChoice;
                cin >> shinyChoice;
                cin.ignore();
                if (shinyChoice == "1") {
                    cout << "\nYou grab a shiny but spiky artifact and lose 20 Worth. [-20]" << endl;
                    dungeonScore -= 20;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter

                }
                else {
                    cout << "\nYou walk past the object. Who cares?" << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
               
            }
            else if (dungeonOutcome == 3) {
                cout << "\nYou discover a secret passage leading to the next level of the dungeon. [+20]" << endl;
                dungeonScore += 20;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (dungeonOutcome == 4) {
                cout << "\nYou dust off what looks to be an armor set..It is! [+50]" << endl;
                dungeonScore += 50;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (dungeonOutcome == 5) {
                cout << "\nYou find a rag you can light on fire to use as a torch. Perfect. [+10]" << endl;
                dungeonScore += 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (dungeonOutcome == 6) {
                cout << "\nYou hear bones rattling..." << endl;
                cout << endl;

                cout << "\nIt's a SKELETON!" << endl;
                cout << endl;
                cout << endl;

                std::string skeletonArt = R"(
                                             _.--""-._
                 .                         ."         ".
                / \    ,^.         /(     Y             |      )\
               /   `---. |--'\    (  \__..'--   -   -- -'""-.-'  )
               |        :|    `>   '.     l_..-------.._l      .'
               |      __l;__ .'      "-.__.||_.-'v'-._||`"----"
                \  .-' | |  `              l._       _.'
                 \/    | |                   l`^^'^^'j
                  ,    | |                _   \_____/     _
                  ,    j |               l `--__)-'(__.--' |
                       | |               | /`---``-----'"1 |  ,-----.
                ,      | |               )/  `--' '---'   \'-'  ___  `-.
                   ,   | |              //  `-'  '`----'  /  ,-'   I`.  \
                     _ L |_            //  `-.-.'`-----' /  /  |   |  `. \
                    '._' / \         _/(   `/   )- ---' ;  /__.J   L.__.\ :
                     `._;/7(-.......'  /        ) (     |  |            | |
                     `._;l _'--------_/        )-'/     :  |___.    _._./ ;
                       | |                 .__ )-'\  __  \  \  I   1   / /
                       `-'                /   `-\-(-'   \ \  `.|   | ,' /
                                          \__  `-'    __/  `-. `---'',-'
                                             )-._.-- (        `-----'
                                            )(  l\ o ('..-.
                                      _..--' _'-' '--'.-. |
                               __,,-'' _,,-''            \ \
                              f'. _,,-'                   \ \
                             ()--  |                       \ \
                               \.  |                       /  \
                                 \ \                      |._  |
                                  \ \                     |  ()|
                                   \ \                     \  /
                                    ) `-.                   | |
                                   // .__)                  | |
                                _.//7'                      | |
                              '---'                         j_| `
                                                           (| |
                                                            |  \
                                                            |lllj
                                                            ||||| 
               )";

                std::cout << skeletonArt << std::endl;

                cout << "\nPress Enter to continue.." << endl;

                cin.get();

                cout << "Do you FIGHT or RUN from the SKELETON? [VERY HIGH RISK](1.FIGHT, 2.RUN)" << endl;
                string skeletonChoice;
                cin >> skeletonChoice;
                cin.ignore();
                if (skeletonChoice == "1") {
                    int skeletonOutcome = rand() % 3;
                    if (skeletonOutcome == 0) {
                        cout << "\nMiraculously, you beat the SKELETON in one blow! You take his SHIELD! [+50]" << endl;
                        dungeonScore += 50;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (skeletonOutcome == 1) {
                        cout << "\nThe SKELETON is stronger than you thought..." << endl;
                        cout << endl;

                        cout << "\nThe monster manages to take a slice out of your stomach." << endl;

                        cout << "\nThis is not good.. [-120]" << endl;
                        dungeonScore -= 120;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (skeletonOutcome == 2) {
                        cout << "\nThe SKELETON didn't actually want to fight. He pleads for his life, offering his SWORD and SHIELD! [+75]" << endl;
                        dungeonScore += 75;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (skeletonOutcome == 3) {
                        cout << "\nThe SKELETON rips his skull off of his spine, and throws it at you before running away. [-50]" << endl;
                        dungeonScore -= 50;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (skeletonOutcome == 4) {
                        cout << "\nThe SKELETON braces to fight you! He steps towards you menacingly!" << endl;
                        cout << "\nThe SKELETON...disintegrates into dust? I guess he was too old. [+10]" << endl;

                        dungeonScore += 10;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (skeletonOutcome == 5) {
                        cout << "\nThe SKELETON braces to fight you! He has a friend!" << endl;
                        cout << "\nThe other SKELETON pulls him aside. 'Hey bro, not cool.' They both leave you alone. [+0]" << endl;

                        dungeonScore += 0;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou RUN from the SKELETON! He manages to get a slice in before you're gone! [-10]" << endl;
                    dungeonScore -= 10;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
             
            }
            else if (dungeonOutcome == 7) {
            cout << "Someone hears your presence. They scream out to you manically for help! You walk to where you heard them." << endl;
            cout << endl;

            cout << "Upon investigation, it seems there is a prisoner being held in the Dungeon. You ask him who he is.." << endl;
            cout << endl;

            cout << "``PLEASE HELP ME, THEY'RE COMING BACK - YOU HAVE TO MAKE A CHOICE NOW.``" << endl;
            cout << endl;
            cout << endl;

            string prisonerArt =
                "*************#*************************%%%%***************************#***********\n"
                "*************#*************************%+**%%****************************#****#***\n"
                "**#*************************************++*###***********************#**#*********\n"
                "*************#*******************+*****##%##%+***********************#***********#\n"
                "*********#*******#***************#%++*******+=*##********************#************\n"
                "*************#*****************++==*%*==*+++*##+=+**%****************#************\n"
                "*************#*********#%=*+***%%%%###%##*#%%##%%%%**++**#**#*********************\n"
                "**********#**********##+=##########*##+****+###***%%%%%##=******#***#***#*********\n"
                "**####******###*********######*******%**+***##*******+*#%%###*******##******###*#*\n"
                "**************####**#######***************+*##**************####****#*************\n"
                "**************#****####**************%##%%####*****************###**#*************\n"
                "**************#*####*****************#*******#******************###*#***********#*\n"
                "****************###*****************#********#**********************#*************\n"
                "*****************************#*****##********##********************##*************\n"
                "***************#*******************#**********##*******************#**************\n"
                "***************#*******************#***********#*******************#**************\n"
                "***************#******************#************##******************#**************\n"
                "***************#******************#*****####****#******************#**************\n"
                "***************#****************#*#*****#*******#******************#**************\n"
                "***************################**#*****##**##***#**#**************##**************\n"
                "**************##****************+#*#**##****##**##*#################**************\n";

            cout << prisonerArt << endl;

            cout << "\nPress Enter to continue.." << endl;

            cin.get();

            cout << "Do you unchain the prisoner? [VERY HIGH RISK](1.Yes, 2.No)" << endl;
            string prisonerChoice;
            cin >> prisonerChoice;
            cin.ignore();
            if (prisonerChoice == "1") {
                int prisonerOutcome = rand() % 3;
                if (prisonerOutcome == 0) {
                    cout << "\nYou unchain the prisoner. He thanks you, and goes his own way. You feel better about yourself. [+10]" << endl;
                    dungeonScore += 10;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
                else if (prisonerOutcome == 1) {
                    cout << "\nHe turns to you with a wicked smile once he's released.." << endl;
                    cout << endl;

                    cout << "\n``You should've known better than that.``" << endl;

                    cout << "\nThe crazed prisoner tears the flesh from your face while you struggle to fight him off. He murders you in cold blood. [-200]" << endl;
                    dungeonScore -= 200;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
                else if (prisonerOutcome == 2) {
                    cout << "\nThe prisoner turns out to be a wizard testing your kindness. He rewards you with a gift for your good nature. [+100]" << endl;
                    dungeonScore += 100;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }
            else {
                cout << "\nYou decide not to release the prisoner. Could be wise. You feel worse about yourself. [-5]" << endl;
                dungeonScore -= 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            // Pause for a moment to allow the player to read the message
            
            }
            
            if (dungeonScore >= 300) {
                clearScreen();
                cout << "\nCongratulations, " << playerName << "! You have reached a Worth of 200 and won the game!" << endl;
                return dungeonScore; // End the game
            }
            // Check if the player's score has reached or fallen below 0
            if (dungeonScore <= 0) {
                clearScreen();
                cout << "\nSorry, " << playerName << ", you've run out of Worth. Game Over! Try again!" << endl;
                return dungeonScore; // End the game
            }
        }
        else if (choice == "2") {
            // Player decides to exit the dungeon
            cout << "\nYou wisely choose to exit the dungeon." << endl;
            break; // Exit the dungeon adventure loop
        }
        else {
            cout << "\nInvalid choice. Please try again." << endl;
        }
    }

    return dungeonScore;
}

int adventure() {
    int score = 50;

    while (true) {
        clearScreen();
        cout << "Your adventure thrives, " << playerName << "!" << endl;
        cout << "\n1. Force A Random Choice" << endl;
        cout << "\n2. Quit" << endl;
        cout << "\nYour current Worth: " << score << endl;

        string choice;
        cin >> choice;
        cin.ignore();

        if (choice == "1") {
            int randomOutcome = rand() % 41; // Generate a random number to determine the outcome

            if (randomOutcome == 0) {
                cout << "\nYou encountered a friendly tailor who gave you a free robe! [+10]" << endl;
                score += 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 1) {
                cout << "\nYou stumbled into a dangerous trap and lost some health. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 2) {
                cout << "\nYou run across a mule. He kicks your money sack over the cliff. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 3) {
                cout << "\nA sweet old lady gives you a piece of chocolate. Win! [+5]" << endl;
                score += 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 4) {
                cout << "\nYou see an apple tree. You were starving. Finally. [+5]" << endl;
                score += 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 5) {
                cout << "\nOh no! Bandits cross paths with you! There's too many of them.. They took some money, food, and your self dignity. [-15]" << endl;
                score -= 15;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 6) {
                cout << "\nIs that..A golden sword? Sweet! [+15]" << endl;
                score += 15;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 7) {
                clearScreen();
                cout << "\nYou see an entrance to a Dungeon. It looks VERY dangerous. Do you enter? (HIGH RISK) (1.Yes,2.No)" << endl;
                string dungeonChoice;
                cin >> dungeonChoice;
                cin.ignore();
                if (dungeonChoice == "1") {
                    score = dungeonAdventure(score);
                }
                else {
                    cout << "\nYou decline to enter the Dungeon. Could be wise." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }
            else if (randomOutcome == 8) {
                cout << "\nA mysterious merchant appears out of nowhere and offers you a rare artifact in exchange for 20 Worth. (1.Buy, 2.Decline)" << endl;
                string merchantChoice;
                cin >> merchantChoice;
                cin.ignore();
                if (merchantChoice == "1") {
                    if (score >= 20) {
                        cout << "\nYou acquire a valuable artifact but lose 20 Worth. [-20]" << endl;
                        score -= 20;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else {
                        cout << "\nYou don't have enough Worth to make the purchase. The merchant vanishes." << endl;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou decline the merchant's offer. The merchant vanishes into thin air." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 9) {
                cout << "\nA wise old sage imparts his knowledge to you. You gain valuable wisdom. [+20]" << endl;
                score += 20;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 10) {
                cout << "\nYou find a hidden passage that leads to a lush garden. You rest and rejuvenate. [+12]" << endl;
                score += 12;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 11) {
                cout << "\nA mischievous imp steals some of your Worth and disappears. [-10]" << endl;
                score -= 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 12) {
                cout << "\nA mysterious portal appears before you. Do you dare to enter? [MED RISK] (1.Yes, 2.No)" << endl;
                string portalChoice;
                cin >> portalChoice;
                cin.ignore();
                if (portalChoice == "1") {
                    int portalOutcome = rand() % 6;
                    if (portalOutcome == 0) {
                        cout << "\nYou are transported to a treasure vault! You gain a considerable sum. [+30]" << endl;
                        score += 30;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (portalOutcome == 1) {
                        cout << "\nYou are transported to a relaxing world. Take a breath. [+10]" << endl;
                        score += 10;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (portalOutcome == 2) {
                        cout << "\nYou are transported to an ominous universe. Gives you the creeps. [-10]" << endl;
                        score -= 10;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (portalOutcome == 3) {
                        cout << "\nThe portal fails and it takes your arm and not the rest of your body. Oh no! [-30]" << endl;
                        score -= 30;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (portalOutcome == 4) {
                        cout << "\nYou are transported to a world of FOOD. Stock up! [+25]" << endl;
                        score += 25;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if(portalOutcome == 5) {
                        cout << "\nThe portal leads to a perilous dimension. You lose some Worth. [-20]" << endl;
                        score -= 20;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou decide not to enter the mysterious portal." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }
            else if (randomOutcome == 13) {
                cout << "\nA babboon leaps from the tree next to you and BONKS your head. Ouch. [-10]" << endl;
                score -= 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 14) {
                cout << "\nA stray cat crosses paths with you. He lets you pet it. [+10]" << endl;
                score += 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 15) {

            string streamArt =
                " ::   ::   ::   ::   ::   ::   ::   ::  :::  :::  ::   ::   ::   ::  :::  :::  ::   ::   ::   ::   :: \n"
                ":%*+*%%*+*#%++*%#++*%#++#%#++#%#++#%#+*#%++*##*++%#++#%#++#%%++#%*++##*++%#*++%#*+*%%++*%#++*%#++%*+\n"
                " *#************#*******++++===+**************#***##******************#***#****##****#*************#\n"
                " +*%#++*%#=-**=::==-==#%@@@@@@@%**++*%#++#%#++#%#++#%*++%%*=+%%*=*%%++#%%++#%#++#%*++#%*=+%%*=*%%++*%:\n"
                "-%*==#*-:=+*#%@@@@@@@@@*=+=--*##++%%*=+%%+=+%%*=+%%+=#%%==#%%+=#%*=+%%*=+%%*=+%%*=*%%+=*%%=+#%#=+#%*+\n"
                " ++*=#%@@@@@@@@@%*-:-*#++*%%+++%%+=*%#++#%#++#%#++#%*++%%+++%%*=*%#++#%%++*%#++#%*++#%*++%%*=*%%++*%:\n"
                " #+@@@@@%%%%%%%@+.=+##*+*#*++###+**#***##*+*##*+*##*+*##++*##+**#***##*+*##*+*##*+*##*+*##+**#****#*+\n"
                ":%+@@@@%%%%%%%%@@@+:--:-*#*++#%#++#%*+*%%+++%%*++%#++#%#++#%%++#%*++#%*++%%*++%#++*%%++#%%++#%#++#%#+\n"
                " ++*-%@@@@@@%%%%%@@@@@@%+--==..-**==*%#+=%%#=+#%#++#%+++%%*=+%%+=*%%++#%%+=#%#++#%*=+%%*=+%%*=*%%++*%-\n"
                ":%*==*+::+@@@@@@@@@@%%@@@@@@@@@@#*+=-::=+-:=#%+=+%#+=#%%==#%%=+#%*=+%%*=+%%*=+%%+=*%%+=*%%=+#%#+=#%*=\n"
                " **#**+*#+=----=#@@@@@@@@@@@%%@@@@@@@@@@@@@@@@%=:.:-**********#****##**##****#***##***##****#***#\n"
                ":%*=+%%*=*%%+=*%%==*%#=-++-::=%@@@@%%%%%%%%%%%@@@@@@@@@@@=.=*#=+#%*=+%%*=+%%*=+%%+=*%%+=*%%+=#%#+=#%*+\n"
                " +*%#+=*%#+=%%#++%%#=+%%*=*%%=-::*@@@@@@@@@@@@@@@@@@@@@@@@@+:#%*=*%#+=#%%==*%#=+#%*+=%%*=+%%*=+%%+=*%-\n"
                ":%*=+%%*=*%%+=*%%+=*%#+=#%#+=**=..%@%%%%%%%%%%%%%%%%%%%%@%@@@-+#%*=+%%*=+%%*=+%%+=*%%+=*%%++*%#+=#%#+\n"
                " *******************#**==-:.:*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=*******#****#*********#****#***********\n"
                " +*%#++*%#++#%#++**-..:#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#-.-#%*+*%#++#%%++#%#++#%*++#%*++%%*+*%%++*%:\n"
                ":%*=+%%*=*%%+==+: %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=:--=:-#%%=+#%*=+%%*=+%%*=+%%+=*%%+=*%%+=#%#+=%%*+\n"
                " =*%%==*%#+=%*-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@= =.-*#+=+%%+=+%%+=*%%+=#%%=+#%#=+#%*==%%*=+%%*=+%%+=*%:\n"
                ":#*++##*+*#%++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#..-**++#%#++###++#%*++#%*++#%*+*##*+*%#++*##++*#*++#%*+\n"
                " #***##***##*-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*=. :---=+##***#***##*+*##*+*##*+*##***##***#*+**#**\n"
                " =*%#++*%#+=%#+:#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-  .-..:+*+=#%%++#%#=+#%*++%%*=+%%*=*%%+=*%-\n"
                "-%*=+%%*=*%%+=+#*. :*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:..   =++=+%%+=*%%+=*%%+=#%#+=#%*+\n"
                " +*%#+=*%#+=%%#++%#*=---. .:=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:..  =*+=+%%*=+%%*=*%%++*%:\n"
                " **#****#****#****#*+**#***#+-... .:%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-..--+**##***##***#\n"
                ":%*+*##*+*#%++*%#++*%#++#%#++#%#++##=....-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=:-:=#%*++#%*+\n"
                " +*%#+=#%#+=%%#++%%#=+%%*=*%%+=*%%+=*%#+=*+- :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:.:+%%+=*%:\n";
                cout << streamArt << endl;


                std::cout << "Press Enter to continue.." << std::endl;

                std::cin.get();

                cout << "You come across a small stream. Do you dare to drink? [MED RISK] (1.Yes, 2.No)" << endl;
                string waterChoice;
                cin >> waterChoice;
                cin.ignore();
                if (waterChoice == "1") {
                    int waterOutcome = rand() % 3;
                    if (waterOutcome == 0) {
                        cout << "\nYou feel hydrated and refreshed! [+20]" << endl;
                        score += 20;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (waterOutcome == 1) {
                        cout << "\nYou quenched your thirst. It tasted awful. Tummy Hurty. [+5]" << endl;
                        score += 5;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (waterOutcome == 2) {
                        cout << "\nYou bend down to take a sip, when a fish jumps and slaps you in the face. Not cool. Not refreshing. [-15]" << endl;
                        score -= 15;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou decide not to drink from the stream. Could be wise." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }

            else if (randomOutcome == 16) {

            string shackArt =
                
                "                       :*%=                                 \n"
                "                   **:=%##::::...         += :-             \n"
                "                .=#*%%%%%%##%%#*%%%#**+==-*%%**.            \n"
                "               :@%###%%#%%+======++++++*#*####              \n"
                "              .*+%**+#*=%*%===================%.            \n"
                "           .*++%#%*==#*==*%@*=****==#*%+#+*=#+@%:           \n"
                "          *@#%#*+#+=*##*=++#%****##%%*%*%%*%%*%+#:          \n"
                "        .=+##*+**#++#%****=**#*%#++*+%=*=+===*===*:         \n"
                "      -=+*%#+==%%#=+++*#*%=******============*=*+*%+        \n"
                "    :*+*%#**=+*%##=+#*+#*#=*+******========***%%#%#%#:      \n"
                "  .+%*#%***+=*%#*#=***+#**=#+*****%**%*#+%*%%%%%%%#***+:    \n"
                "  *%%%%%@*#*+%#**%=*+++#**=%=**#*#*%@%#%%%%%#*%#**+*+#**=.  \n"
                ".*%%%#%*****#%%%#%#@##*###+@**%@@@%#%@%#+**+***#%#**%+%*%%= \n"
                "###%@#*#*%%%#***%#*++***######*#**##*%**%**##*@%%*@@%%%#*#+\n"
                " .**+**#**+++##=#++%%%%@**++=+*#*+%%*%%%%%%@*%#*%**#=**- .  \n"
                "    :*%%#+=+*#*=#==*+*++*#********@%**%*##%@@##%*++**+@:    \n"
                "    .*###+=+*#*=%==*=*=+**+=*+**+*@+%*%*%%%%%****=+**+%     \n"
                "    .#**#+=*##+=%==*+*=***=*****++@++++++###%****=+***+     \n"
                "    .%***=+*%*=+#=+*+*+#**=***%**+@+=+++=##%%****++**#+     \n"
                "    :%+*==##*+=%#+*#*#+*%#=#%#%=#+@+++++=##%%##%#+++**=     \n"
                "    :#+*==#%++=%#*+##%+*%*=#%#%=#+@****==%%##%%%%*+***=     \n"
                "    :@=*+=*%+*=#%#=*%%=+%*=%@#%=#*@****==%%**#%#%%#**%%:    \n"
                "    =@=#*+*#+*=*%%=+%%*+%*=%@%@=%*@****++%%%*++**+-::.      \n"
                "  =#*#*%#%%%**++%%*+#%*+##=%@%@%%@@*%****#+=::..            \n"
                "  .::-==+***#********+******%@@@@@@@%%-:.                   \n"
                "            ..::::::::---===+*%*+--. .                      ";

            // Print the ASCII art
            std::cout << shackArt << std::endl;

            cout << "Press enter to continue..." << std::endl;
            cin.get();

                cout << "\nYou notice what looks to be an abandoned shack off the path. Do you search for supplies? [HIGH RISK] (1.Yes, 2.No)" << endl;
                string shackChoice;
                cin >> shackChoice;
                cin.ignore();
                if (shackChoice == "1") {
                    int shackOutcome = rand() % 3;
                    if (shackOutcome == 0) {
                        cout << "\nYou find some bandages to heal up. Perfect. [+50]" << endl;
                        score += 50;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (shackOutcome == 1) {
                        cout << "\nUpon opening the shack door, a crazed lunatic pokes you in the eye. [-25]" << endl;
                        score -= 25;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (shackOutcome == 2) {
                        cout << "\nUpon opening the shack door, a stray dog comes up to you. He takes a chomp. [-35]" << endl;
                        score -= 35;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou decide to keep walking. Could be wise." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
              
            }

            else if (randomOutcome == 17) {
                cout << "\nA falcon poops on your head. Gross. [-10]" << endl;
                score -= 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }

            else if (randomOutcome == 18) {
                cout << "\nA friendly passerby gives you a piece of bread for your travels. Nice fellow. [+10]" << endl;
                score += 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }

            else if (randomOutcome == 19) {
            cout << "\nA fairy blesses you with Worth! [+25]" << endl;

            string fairyArt = R"(
                                 ,_  .--.
                          , ,   _)\/    ;--.
                  . ' .    \_\-'   |  .'    \
                 -= * =-   (.-,   /  /       |
                  ' .\'    ).  ))/ .'   _/\ /
                      \_   \_  /( /     \ /(
                      /_\ .--'   `-.    //  \
                      ||\/        , '._//    |
                      ||/ /`(_ (_,;`-._/     /
                      \_.'   )   /`\       .'
                           .' .  |  ;.   /`
                          /      |\(  `.(  +
                         |   |/  | `    `
                         |   |  /
                         |   |.'
                      __/'  /
                  _ .'  _.-`
               _.` `.-;`/
              /_.-'` / /
                    | /
                   ( /
                  /_/
             )";

            std::cout << fairyArt << std::endl;
            score += 25;
            // Pause for a moment to allow the player to read the message
            waitForEnter(); // Wait for user to press Enter
            }

            else if (randomOutcome == 20) {
                cout << "\nYou're walking in the forest..A CAT wearing a balaclava leaps from the bushes! He snatches your dabloons!\n This makes you sad. :( [-20]" << endl;
                score -= 20;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            
            
            else if (randomOutcome == 21) {

        

                string dragonstandingArt = "(insert dragon)";
                
        

            // Print the ASCII art
            std::cout << dragonstandingArt << std::endl;

            cout << "Press enter to continue..." << std::endl;
            cin.get();

                cout << "\n A DRAGON flies from the sky and lands before you! He is challenging you. Do you fight? [EXTREME HIGH RISK, HIGH REWARD] (1.Yes, 2.No)" << endl;
                string dragonChoice;
                cin >> dragonChoice;
                cin.ignore();
                if (dragonChoice == "1") {
                    int dragonOutcome = rand() % 4;
                    if (dragonOutcome == 0) {
                        cout << "\nThe DRAGON smites you down with his oversized claws. Too easy. [-200]" << endl;
                        score -= 200;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (dragonOutcome == 1) {
                        cout << "\nThe DRAGON breathes FIRE all around you. Almost like he's playing with his food. It's getting hot. [-20]" << endl;
                        score -= 20;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                   
                   else if (dragonOutcome == 2) {
                    cout << "\nThe DRAGON attempts to SWIPE at you! How will you react? [1.Jump, 2.Block, 3. A Third Option]" << endl;
                    string dragonSwipeChoice;
                    cin >> dragonSwipeChoice;
                    cin.ignore();
                    if (dragonSwipeChoice == "1") {
                        int dragonSwipeChoiceJumpOutcome = rand() % 3;
                        if (dragonSwipeChoiceJumpOutcome == 0) {
                            cout << "\nYou try to JUMP but can't JUMP that high! He smacks you down! [-100]" << endl;
                            score -= 50;
                            waitForEnter();
                        }
                        else if (dragonSwipeChoiceJumpOutcome == 1) {
                            cout << "\nYou attempt to JUMP over his SWIPE!\nOh no!\nYou lost balance..he hit you. [-50]" << endl;
                            score -= 50;
                            waitForEnter();
                        }
                        else if (dragonSwipeChoiceJumpOutcome == 2) {
                            cout << "\nYou JUMP over the SWIPE! Stuck the landing, too! No damage taken. [+0]" << endl;
                            score += 0;
                            waitForEnter();
                        }
                    }
                    if (dragonSwipeChoice == "2") {
                        int dragonSwipeChoiceBlockOutcome = rand() % 2;
                        if (dragonSwipeChoiceBlockOutcome == 0) {
                            cout << "\nYou try to BLOCK! He's too strong. His claws went straight through you! [-100]" << endl;
                            score -= 100;
                            waitForEnter();
                        }
                        else if (dragonSwipeChoiceBlockOutcome == 1) {
                            cout << "\nYou successfully BLOCKED the DRAGON'S attack! He's suprised! ... so are you. [+0]" << endl;
                            score += 0;
                            waitForEnter();
                        }
                    }
                    if (dragonSwipeChoice == "3") {
                        cout << "\nYou hit him mid. Fucking. Swing." << endl;
                        cout << "\nHe was not ready for this. He is vanquished. [+200]" << endl;
                    }
                   }
                   else if (dragonOutcome == 3) {
                    cout << "\nThe DRAGON has a WEAKSPOT you notice! In its eye! Do you try to take advantage of this? [1.Yes, 2.No]" << endl;
                    string dragonWeakSpotChoice;
                    cin >> dragonWeakSpotChoice;
                    cin.ignore();
                    if (dragonWeakSpotChoice == "1") {
                        int dragonWeakSpot1Outcome = rand() % 4;
                        if (dragonWeakSpot1Outcome == 0) {
                            cout << "\nYou JUMP with your dagger pointed towards its eye! You hit it perfectly!" << endl;
                            cout << "\nThe DRAGON roars a sound you never thought possible." << endl;
                            cout << "\nThe DRAGON dies, leaving behind its precious bones as a REWARD. [+150]" << endl;
                            score += 150;
                            waitForEnter();
                        }
                        else if (dragonWeakSpot1Outcome == 1) {
                            cout << "\nYou JUMP with your dagger pointed towards its eye! You barely press it into the eye before he swipes you down. It hurt him, badly." << endl;
                            cout << "The DRAGON flees to its lair. You survive another day. [+80]" << endl;
                            score += 80;
                            waitForEnter();
                        }
                        else if (dragonWeakSpot1Outcome == 2) {
                            cout << "\nYou JUMP with your dagger pointed towards its eye! You get almost to it before the DRAGON lifts its head and swallows you whole." << endl;
                            cout << "\nOops.. [-300]" << endl;
                            score -= 300;
                            waitForEnter();
                        }
                        else if (dragonWeakSpot1Outcome == 3) {
                            cout << "\nYou JUMP with your dagger pointed towards its eye! You forgot to eat breakfast this morning, though." << endl;
                            cout << "\nYou couldn't reach him. He laughs at you and hurts your pride. [-35]" << endl;
                            score -= 35;
                            waitForEnter();
                        }
                    }
                    if (dragonWeakSpotChoice == "2") {
                        cout << "\nYou decide not to take advantage of the WEAKSPOT. It's very close to its mouth. Sharp teeth. That's a no-no." << endl;
                        cout << "\nCould be wise." << endl;
                        cout << "\nInstead, you choose to swipe at his feet. Hurts. [+65]" << endl;
                        score += 65;
                        waitForEnter();
                    }
                   }
                   
                }

                else if (dragonChoice == "2") {
                    cout << "\nYou run for your life! He allows you to escape. This time..[+0]" << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }

                
              
            }
            else if (randomOutcome == 22) {
                cout << "\nA mischievous squirrel steals some of your food while you're distracted. [-3]" << endl;
                score -= 3;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 23) {
                cout << "\nYou find an abandoned treasure chest hidden under a rock. Jackpot! [+10]" << endl;
                score += 10;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 24) {
                cout << "\nA sudden rainstorm hits, soaking all your supplies. What a day. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 25) {
                cout << "\nYou come across a traveling merchant who gives you a free potion. Lucky day! [+7]" << endl;
                score += 7;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 26) {
                cout << "\nYou stumble into quicksand but manage to escape, losing some items in the process. [-8]" << endl;
                score -= 8;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 27) {
                cout << "\nYou help a lost child find their way home. Their grateful parent rewards you with a shiny coin. [+5]" << endl;
                score += 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 28) {
                cout << "\nA traveling bard entertains you with a song, lifting your spirits. [+3]" << endl;
                score += 3;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 29) {
                cout << "\nYou accidentally step on a thorny bush. Ouch! That hurts. [-2]" << endl;
                score -= 2;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 30) {
                cout << "\nYou stumble upon a forgotten campfire with some leftover supplies. [+6]" << endl;
                score += 6;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }  
            else if (randomOutcome == 31) {
                cout << "\nA mysterious figure offers you advice, but you're unsure if it's good or bad. No change in score." << endl;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 32) {
                cout << "\nA wild boar charges at you, but you manage to dodge just in time. Phew! [-4]" << endl;
                score -= 4;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 33) {
                cout << "\nYou find a hidden path that saves you a lot of time. Things are looking up! [+8]" << endl;
                score += 8;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 34) {
                cout << "\nYou slip on a wet rock and twist your ankle. That's going to slow you down. [-6]" << endl;
                score -= 6;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 35) {
                cout << "\nA rare flower blooms in front of you, and its beauty lifts your mood. [+4]" << endl;
                score += 4;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 36) {
                cout << "\nYou encounter a wandering healer who tends to your wounds. [+7]" << endl;
                score += 7;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 37) {
                cout << "\nA large boulder blocks your path, and you have to find a way around. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                waitForEnter(); // Wait for user to press Enter
            }
            else if (randomOutcome == 38) {
                cout << "\nYou come across a deep, dark cave. Do you want to explore it? [MEDIUM RISK] (1.Yes, 2.No)" << endl;
                string caveChoice;
                cin >> caveChoice;
                cin.ignore();
                if (caveChoice == "1") {
                    int caveOutcome = rand() % 3;
                    if (caveOutcome == 0) {
                        cout << "\nYou find a hidden treasure chest filled with gold. Jackpot! [+40]" << endl;
                        score += 40;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (caveOutcome == 1) {
                        cout << "\nA swarm of bats flies out of the cave, biting you as they pass. [-20]" << endl;
                        score -= 20;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (caveOutcome == 2) {
                        cout << "\nThe cave leads to a dead end, and you wasted valuable time. [-10]" << endl;
                        score -= 10;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou decide to play it safe and walk past the cave. Wise choice." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }

            else if (randomOutcome == 39) {
                cout << "\nYou spot an old man sitting by a fire. He offers to share his meal. Do you accept? [LOW RISK] (1.Yes, 2.No)" << endl;
                string mealChoice;
                cin >> mealChoice;
                cin.ignore();
                if (mealChoice == "1") {
                    int mealOutcome = rand() % 3;
                    if (mealOutcome == 0) {
                        cout << "\nThe meal was hearty and delicious. You feel stronger. [+30]" << endl;
                        score += 30;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (mealOutcome == 1) {
                        cout << "\nYou realize too late that the food was spoiled. You fall ill. [-15]" << endl;
                        score -= 15;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (mealOutcome == 2) {
                        cout << "\nThe old man tells you a story that gives you a new perspective. No change in score." << endl;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                }
                else {
                    cout << "\nYou politely decline and continue on your journey." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }

            else if (randomOutcome == 40) {
                cout << "\nYou stumble upon a mysterious, glowing artifact buried in the ground. Do you dig it up? [HIGH RISK] (1.Yes, 2.No)" << endl;
                string artifactChoice;
                cin >> artifactChoice;
                cin.ignore();
                if (artifactChoice == "1") {
                    int artifactOutcome = rand() % 3;
                    if (artifactOutcome == 0) {
                        cout << "\nYou successfully dig up a powerful relic! It grants you enhanced strength. [+50]" << endl;
                        score += 50;
                        // Pause for a moment to allow the player to read the message
                        waitForEnter(); // Wait for user to press Enter
                    }
                    else if (artifactOutcome == 1) {
                        cout << "\nAs you dig, a hidden trap is triggered, and a barrage of arrows hits you. [-30]" << endl;
                        score -= 30;
                        cout << "\nDo you use one of your health potions to recover? (1.Yes, 2.No)" << endl;
                        string potionChoice;
                        cin >> potionChoice;
                        if (potionChoice == "1") {
                            cout << "\nYou drink the potion and regain some health. [+20]" << endl;
                            score += 20;
                            // Pause for a moment to allow the player to read the message
                            waitForEnter(); // Wait for user to press Enter
                        } else {
                            cout << "\nYou decide to save the potion and continue wounded." << endl;
                            // Pause for a moment to allow the player to read the message
                            waitForEnter(); // Wait for user to press Enter
                        }
                    }
                    else if (artifactOutcome == 2) {
                        cout << "\nAs you uncover the artifact, a strange energy weakens you. [-20]" << endl;
                        score -= 20;
                        cout << "\nDo you attempt to study the artifact further or leave it? (1.Study, 2.Leave)" << endl;
                        string studyChoice;
                        cin >> studyChoice;
                        if (studyChoice == "1") {
                            cout << "\nYour study reveals ancient knowledge. You feel enlightened! [+30]" << endl;
                            score += 30;
                            // Pause for a moment to allow the player to read the message
                            waitForEnter(); // Wait for user to press Enter
                        } else {
                            cout << "\nYou leave the artifact behind and continue your journey." << endl;
                            // Pause for a moment to allow the player to read the message
                            waitForEnter(); // Wait for user to press Enter
                        }
                    }
                }
                else {
                    cout << "\nYou decide it's best not to mess with mysterious artifacts. You continue on your path." << endl;
                    // Pause for a moment to allow the player to read the message
                    waitForEnter(); // Wait for user to press Enter
                }
            }






            // Checks if the player's score has reached 100
            if (score >= 200) {
                clearScreen();
                cout << "Congratulations, " << playerName << "! You have reached a Worth of 200 and won the game!" << endl;
                return score; // End the game
            }

            // Check if the player's score has reached or fallen below 0
            if (score <= 0) {
                clearScreen();
                cout << "Sorry, " << playerName << ", you've run out of Worth. Game Over! Try again!" << endl;
                return score; // End the game
            }

        }
        else if (choice == "2") {
            cout << "Quitting..." << endl;
            // Pause for a moment to allow the player to read the message
            waitForEnter(); // Wait for user to press Enter
            break;
        }
        else {
            cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
            // Pause for a moment to allow the player to read the message
            waitForEnter(); // Wait for user to press Enter
        }
    }

    return score;
}


int main() {
    srand(time(nullptr)); // Seed for random number generation

    while (true) {
        clearScreen();
        displayIntro();

        // Start measuring time
        auto startTime = chrono::steady_clock::now();

        int finalScore = adventure();

        // Stop measuring time
        auto endTime = chrono::steady_clock::now();

        // Calculate elapsed time
        chrono::duration<double> elapsedSeconds = endTime - startTime;

        // Clear the screen before displaying the final score
        clearScreen();

        if (finalScore >= 200) {
            cout << "\nYou have proved your Worth. Well done, " << playerName << "." << endl;
            cout << endl;
            cout << "\nYour final score: " << finalScore << endl;
            cout << endl;
        }
        else {
            cout << "\nYou have let me down, " << playerName << "." << endl;
            cout << endl;
            cout << "\nYour final score: " << finalScore << endl;
            cout << endl;
        }

        // Display elapsed time rounded to two decimal places
        cout << "\nElapsed Time: " << fixed << setprecision(2) << elapsedSeconds.count() << " seconds" << endl;


        cout << "\nDeveloper's Best Time: 97.68 seconds." << endl;
        cout << endl;

        cout << "\nProve your Worth again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        if (playAgain != "yes") {
            cout << "\nSee you next time, Worthless adventurer." << endl;
            break; // Exit the loop and end the program if the player doesn't want to play again
        }
    }

    return 0;
}
