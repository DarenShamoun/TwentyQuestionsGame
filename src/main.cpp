//Daren Shamoun
#include "tree.h"
#include "datamgmt.h"
#include "options.h"
#include "twentyq.h"

#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char** argv)
{
    //get user options from command line
    auto playerOptions = mesa::get_options(argc, argv);

    while(playerOptions.again)
    {
        //create ifstream object with data files name
        std::ifstream inputStream(playerOptions.filename);

        //make sure the ifstream is open
        if (!inputStream.is_open())
        {
            std::cerr << "Error: failed to open file '" << playerOptions.filename << "'\n";
            return 1;
        }

        //initialize the game tree based on the user options with the ifstream
        mesa::tree<std::string>* root = mesa::initialize_tree(playerOptions, inputStream);

        std::cout << "\nWelcome to 20 Questions!\n";
        std::cout << "Think of an object and I will try to guess it.\n";
        std::cout << "Please answer yes or no to the following questions about your object.\n\n";
        
        // start the game
        root = mesa::play_game(root);

        // save the game tree to a file
        std::ofstream outputStream(playerOptions.filename);
        mesa::save_game(root, outputStream);

        // clean up memory
        mesa::delete_tree(root);
        root = nullptr;

        std::cout << "Would you like to play again? (yes/no)\n";
		playerOptions.again = mesa::yes_no();
    }
    
	std::cout << "Goodbye!\n";

    return 0;
}