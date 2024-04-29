#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <list>
#include <string>

std::string cherry = "\U0001F352";
std::string grape = "\U0001F347";
std::string peach = "\U0001F351";

// Reel strings
std::string reel1 = "";
std::string reel2 = "";
std::string reel3 = "";

std::list<std::string> initializeList()
{
    std::list<std::string> symbols;

    symbols.push_back(cherry);
    symbols.push_back(cherry);
    symbols.push_back(cherry);

    symbols.push_back(grape);
    symbols.push_back(grape);
    symbols.push_back(grape);

    symbols.push_back(peach);
    symbols.push_back(peach);
    symbols.push_back(peach);

    return symbols;
}

void spinReels()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);
    // Pick random symbol indexes
    int index1 = dis(gen);
    int index2 = dis(gen);
    int index3 = dis(gen);
    // Set symbol characters in reel strings
    std::list<std::string> symbols = initializeList();
    std::list<std::string>::iterator symbolA = symbols.begin();
    std::advance(symbolA, index1);
    reel1 = *symbolA;
    std::list<std::string>::iterator symbolB = symbols.begin();
    std::advance(symbolB, index2);
    reel2 = *symbolB;
    std::list<std::string>::iterator symbolC = symbols.begin();
    std::advance(symbolC, index3);
    reel3 = *symbolC;
    // Print slot machine
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣤⣤⣀⠀⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣿⡇⠀⠀⣤⣄⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⠀⠛⠛⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸" << reel1 << "⡇⢸" << reel2 << "⡇⢸" << reel3 << "⡇⠀⣿⡇⠀⠀⣷⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⣾⡇⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿⡇⠀⣿⡿⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠙⠃⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⢀⣴⣿⠟⠛⠛⢻⡿⠛⠛⠛⢻⣿⣿⡟⠋⠉⠉⠛⢿⣦⡀⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⢰⣿⣿⣥⣤⣤⣤⣾⣧⣤⣤⣤⣿⣿⣿⣷⣦⣤⣤⣶⣿⣿⣿⡆⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀" << std::endl;
    std::cout << "⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀" << std::endl;
}

void getInput()
{
    std::cout << "-----Press enter to spin!-----";
    std::cin.ignore();
}

int main()
{
    // Clears the players screen
    system("clear");
    while (true)
    {
        // Get user input
        getInput();

        // Spin for 1 second
        auto start = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start <
               std::chrono::seconds(1))
        {
            // Clears the players screen
            system("clear");

            spinReels();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        // Clears the players screen
        system("clear");

        // Show results
        std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣤⣤⣀⠀⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣿⡇⠀⠀⣤⣄⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⠀⠛⠛⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸" << reel1 << "⡇⢸" << reel2 << "⡇⢸" << reel3 << "⡇⠀⣿⡇⠀⠀⣷⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⣾⡇⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿⡇⠀⣿⡿⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠙⠃⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⢀⣴⣿⠟⠛⠛⢻⡿⠛⠛⠛⢻⣿⣿⡟⠋⠉⠉⠛⢿⣦⡀⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⢰⣿⣿⣥⣤⣤⣤⣾⣧⣤⣤⣤⣿⣿⣿⣷⣦⣤⣤⣶⣿⣿⣿⡆⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀" << std::endl;
        std::cout << "⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀" << std::endl;

        // Wait before next spin
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}