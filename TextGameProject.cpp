#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

using namespace std;

string playerName; // Global variable to store the player's name
atomic<bool> quitGame(false); // Atomic flag to signal game exit


// Function to clear the screen
void clearScreen() {
    system("cls"); // For Windows
}

// Function to display the game's greeting and rules
void displayIntro() {
   
    cout << "Welcome to Dungeoneer's Odyssey!" << endl;
    cout << "Worth Goal: 200" << endl;
    cout << "If your Worth reaches 0, you lose." << endl;
    cout << endl;

    cout << "Character name: ";
    getline(cin, playerName); // Read the player's name and store it in the global variable
    cout << endl;

    clearScreen();
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
        cout << "1. Explore deeper into the dungeon" << endl;
        cout << "2. Turn back and exit the dungeon" << endl;
        cout << "Your current dungeon score: " << dungeonScore << endl;

        string choice;
        cin >> choice;
        cin.ignore();

        if (choice == "1") {
            int dungeonOutcome = rand() % 7; // Generate a random number for dungeon outcomes

            if (dungeonOutcome == 0) {
                cout << "You encountered a dangerous mega-centipede and barely escaped with scratches. [-30]" << endl;
                dungeonScore -= 30;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(2));
            }
            else if (dungeonOutcome == 1) {
                cout << "You found a hidden treasure chest in the dark corners of the dungeon! [+30]" << endl;
                dungeonScore += 30;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (dungeonOutcome == 2) {
                cout << "You see a shiny object poking out of the stone. (1.Inspect, 2.Walk Past)" << endl;
                string shinyChoice;
                cin >> shinyChoice;
                cin.ignore();
                if (shinyChoice == "1") {
                    cout << "You grab a shiny but spiky artifact and lose 20 Worth. [-20]" << endl;
                    dungeonScore -= 20;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(2));
                  
                }
                else {
                    cout << "You walk past the object. Who cares?" << endl;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(2));
                }
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (dungeonOutcome == 3) {
                cout << "You discover a secret passage leading to the next level of the dungeon. [+20]" << endl;
                dungeonScore += 20;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (dungeonOutcome == 4) {
                cout << "You dust off what looks to be an armor set..It is! [+50]" << endl;
                dungeonScore += 50;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (dungeonOutcome == 5) {
                cout << "You find a rag you can light on fire to use as a torch. Perfect. [+10]" << endl;
                dungeonScore += 10;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (dungeonOutcome == 6) {
                cout << "Someone hears your presence. They scream out to you manically for help! You walk to where you heard them." << endl;
                cout << endl;

                cout << "Upon investigation, it seems there is a prisoner being held in the Dungeon. You ask him who he is.." << endl;
                cout << endl;

                cout << "``PLEASE HELP ME, THEY'RE COMING BACK - YOU HAVE TO MAKE A CHOICE NOW.``" << endl;
                cout << endl;
                
                cout << "Do you unchain the prisoner? [VERY HIGH RISK](1.Yes, 2.No)" << endl;
                string prisonerChoice;
                cin >> prisonerChoice;
                cin.ignore();
                if (prisonerChoice == "1") {
                    int prisonerOutcome = rand() % 3;
                    if (prisonerOutcome == 0) {
                        cout << "You unchain the prisoner. He thanks you, and goes his own way. You feel better about yourself. [+10]" << endl;
                        dungeonScore += 10;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (prisonerOutcome == 1) {
                        cout << "He turns to you with a wicked smile once he's released.." << endl;
                        cout << endl;

                        cout << "``You should've known better than that.``" << endl;

                        cout << "The crazed prisoner tears the flesh from your face while you struggle to fight him off. He murders you in cold blood. [-200]" << endl;
                        dungeonScore -= 200;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(5));
                    }
                    else if (prisonerOutcome == 2) {
                        cout << "The prisoner turns out to be a wizard testing your kindness. He rewards you with a gift for your good nature. [+100]" << endl;
                        dungeonScore += 100;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                }
                else {
                    cout << "You decide not to release the prisoner. Could be wise. You feel worse about yourself. [-5]" << endl;
                    dungeonScore -= 5;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            if (dungeonScore >= 200) {
                clearScreen();
                cout << "Congratulations, " << playerName << "! You have reached a Worth of 200 and won the game!" << endl;
                return dungeonScore; // End the game
            }
            // Check if the player's score has reached or fallen below 0
            if (dungeonScore <= 0) {
                clearScreen();
                cout << "Sorry, " << playerName << ", you've run out of Worth. Game Over! Try again!" << endl;
                return dungeonScore; // End the game
            }
        }
        else if (choice == "2") {
            // Player decides to exit the dungeon
            cout << "You wisely choose to exit the dungeon." << endl;
            break; // Exit the dungeon adventure loop
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return dungeonScore;
}

int adventure() {
    int score = 50;

    while (true) {
        clearScreen();
        cout << "Your adventure thrives, " << playerName << "!" << endl;
        cout << "1. Force A Random Choice" << endl;
        cout << "2. Quit" << endl;
        cout << "Your current Worth: " << score << endl;

        string choice;
        cin >> choice;
        cin.ignore();

        if (choice == "1") {
            int randomOutcome = rand() % 19; // Generate a random number to determine the outcome

            if (randomOutcome == 0) {
                cout << "You encountered a friendly tailor who gave you a free robe! [+10]" << endl;
                score += 10;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 1) {
                cout << "You stumbled into a dangerous trap and lost some health. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 2) {
                cout << "You run across a mule. He kicks your money sack over the cliff. [-5]" << endl;
                score -= 5;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 3) {
                cout << "A sweet old lady gives you a piece of chocolate. Win! [+5]" << endl;
                score += 5;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 4) {
                cout << "You see an apple tree. You were starving. Finally. [+5]" << endl;
                score += 5;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 5) {
                cout << "Oh no! Bandits cross paths with you! There's too many of them.. They took some money, food, and your self dignity. [-15]" << endl;
                score -= 15;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 6) {
                cout << "Is that..A golden sword? Sweet! [+15]" << endl;
                score += 15;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 7) {
                clearScreen();
                cout << "You see an entrance to a Dungeon. It looks VERY dangerous. Do you enter? (HIGH RISK) (1.Yes,2.No)" << endl;
                string dungeonChoice;
                cin >> dungeonChoice;
                cin.ignore();
                if (dungeonChoice == "1") {
                    score = dungeonAdventure(score);
                }
                else {
                    cout << "You decline to enter the Dungeon. Could be wise." << endl;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }

                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            
                else {
                    cout << "You decline the merchant's offer. The merchant vanishes into thin air." << endl;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(2));
                }
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 8) {
                cout << "A mysterious merchant appears out of nowhere and offers you a rare artifact in exchange for 20 Worth. (1.Buy, 2.Decline)" << endl;
                string merchantChoice;
                cin >> merchantChoice;
                cin.ignore();
                if (merchantChoice == "1") {
                    int waterOutcome = rand() % 3;
                    if (waterOutcome == 0) {
                        cout << "You feel hydrated and refreshed! [+20]" << endl;
                        score += 20;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (waterOutcome == 1) {
                        cout << "You quenched your thirst. It tasted awful. Tummy Hurty. [+5]" << endl;
                        score += 5;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (waterOutcome == 2) {
                        cout << "You bend down to take a sip, when a fish jumps and slaps you in the face. Not cool. Not refreshing. [-15]" << endl;
                        score -= 15;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                }
                else {
                    cout << "You decline the merchant's offer. The merchant vanishes into thin air." << endl;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(2));
                }
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 9) {
                cout << "A wise old sage imparts his knowledge to you. You gain valuable wisdom. [+20]" << endl;
                score += 20;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 10) {
                cout << "You find a hidden passage that leads to a lush garden. You rest and rejuvenate. [+12]" << endl;
                score += 12;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 11) {
                cout << "A mischievous imp steals some of your Worth and disappears. [-10]" << endl;
                score -= 10;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 12) {
                cout << "A mysterious portal appears before you. Do you dare to enter? [MED RISK] (1.Yes, 2.No)" << endl;
                string portalChoice;
                cin >> portalChoice;
                cin.ignore();
                if (portalChoice == "1") {
                    int portalOutcome = rand() % 6;
                    if (portalOutcome == 0) {
                        cout << "You are transported to a treasure vault! You gain a considerable sum. [+30]" << endl;
                        score += 30;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (portalOutcome == 1) {
                        cout << "You are transported to a relaxing world. Take a breath. [+10]" << endl;
                        score += 10;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (portalOutcome == 2) {
                        cout << "You are transported to an ominous universe. Gives you the creeps. [-10]" << endl;
                        score -= 10;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (portalOutcome == 3) {
                        cout << "The portal fails and it takes your arm and not the rest of your body. Oh no! [-30]" << endl;
                        score -= 30;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (portalOutcome == 4) {
                        cout << "You are transported to a world of FOOD. Stock up! [+25]" << endl;
                        score += 25;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    else if (portalOutcome == 5) {
                        cout << "The portal leads to a perilous dimension. You lose some Worth. [-20]" << endl;
                        score -= 20;
                        // Pause for a moment to allow the player to read the message
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                }
                else {
                    cout << "You decide not to enter the mysterious portal." << endl;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 13) {
            cout << "A babboon leaps from the tree next to you and BONKS your head. Ouch. [-10]" << endl;
            score -= 10;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 14) {
            cout << "A stray cat crosses paths with you. He lets you pet it. [+10]" << endl;
            score += 10;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }
            else if (randomOutcome == 15) {
            cout << "You come across a small stream. Do you dare to drink? [MED RISK] (1.Yes, 2.No)" << endl;
            string waterChoice;
            cin >> waterChoice;
            cin.ignore();
            if (waterChoice == "1") {
                int waterOutcome = rand() % 3;
                if (waterOutcome == 0) {
                    cout << "You feel hydrated and refreshed! [+20]" << endl;
                    score += 20;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else if (waterOutcome == 1) {
                    cout << "You quenched your thirst. It tasted awful. Tummy Hurty. [+5]" << endl;
                    score += 5;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else if (waterOutcome == 2) {
                    cout << "You bend down to take a sip, when a fish jumps and slaps you in the face. Not cool. Not refreshing. [-15]" << endl;
                    score -= 15;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
            }
            else {
                cout << "You decide not to drink from the stream. Could be wise." << endl;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }

            /*else if (randomOutcome == 16) {
            cout << "You have died of Dysentery. Better luck next time! [-200]" << endl;
            score -= 200;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }*/

            else if (randomOutcome == 17) {
            cout << "You notice what looks to be an abandoned shack off the path. Do you search for supplies? [HIGH RISK] (1.Yes, 2.No)" << endl;
            string shackChoice;
            cin >> shackChoice;
            cin.ignore();
            if (shackChoice == "1") {
                int shackOutcome = rand() % 3;
                if (shackOutcome == 0) {
                    cout << "You find some bandages to heal up. Perfect. [+50]" << endl;
                    score += 50;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else if (shackOutcome == 1) {
                    cout << "Upon opening the shack door, a crazed lunatic pokes you in the eye. [-25]" << endl;
                    score -= 25;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else if (shackOutcome == 2) {
                    cout << "Upon opening the shack door, a stray dog comes up to you. He takes a chomp. [-35]" << endl;
                    score -= 35;
                    // Pause for a moment to allow the player to read the message
                    this_thread::sleep_for(chrono::seconds(3));
                }
            }
            else {
                cout << "You decide to keep walking. Could be wise." << endl;
                // Pause for a moment to allow the player to read the message
                this_thread::sleep_for(chrono::seconds(3));
            }
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }

            else if (randomOutcome == 18) {
            cout << "A falcon poops on your head. Gross. [-10]" << endl;
            score -= 10;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
            }

            else if (randomOutcome == 19) {
            cout << "A friendly passerby gives you a piece of bread for your travels. Nice fellow. [+10]" << endl;
            score += 10;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
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
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }
        else {
            cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
            // Pause for a moment to allow the player to read the message
            this_thread::sleep_for(chrono::seconds(3));
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
            cout << "You have proved your Worth. Well done, " << playerName << "." << endl;
            cout << endl;
            cout << "Your final score: " << finalScore << endl;
            cout << endl;
        }
        else {
            cout << "You have let me down, "<< playerName << "." << endl;
            cout << endl;
            cout << "Your final score: " << finalScore << endl;
            cout << endl;
        }

        // Display elapsed time rounded to two decimal places
        cout << "Elapsed Time: " << fixed << setprecision(2) << elapsedSeconds.count() << " seconds" << endl;
        cout << endl;

        cout << "Developer's Best Time: 97.68 seconds." << endl;
        cout << endl;


        cout << "Prove your Worth again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        if (playAgain != "yes") {
            cout << "See you next time, Worthless adventurer." << endl;
            break; // Exit the loop and end the program if the player doesn't want to play again
        }
    }

    return 0;
}