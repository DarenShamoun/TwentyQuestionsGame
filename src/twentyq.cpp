//Daren Shamoun
//ID# 5550016094
#include "twentyq.h"


namespace mesa
{
    // play the game
    mesa::tree<std::string>* play_game(mesa::tree<std::string>* tree)
    {
        // if the tree pointer is null, return null
        if (tree == nullptr)
        {
            return nullptr;
        }

        // if we have reached a leaf node, display the value and ask the user
        // if this guess is correct
        if (tree->left == nullptr && tree->right == nullptr)
        {
            std::cout << "Is it " << tree->value << "? (yes/no)\n";
			const bool answer = mesa::yes_no();

            // if the guess is correct, the computer wins
            if (answer)
            {
                std::cout << "Hooray! I guessed correctly!\n";
                return tree;
            }
            // if the guess is incorrect, the user wins
            if (!answer)
            {
                std::cout << "\nIt looks like you have managed to beat me!\n";

                // ask the user for the name of the object they were thinking of
                std::cout << "What was it that you were thinking of?\n";
                const std::string object = get_user_input();

                // ask the user for a question that differentiates their object
                // from the object just guessed by the computer
                std::cout << "What is a question that differentiates " + object + " from " << tree->value << "?:\n";
                const std::string question = get_user_input();

                // ask the user for the answer to the new question (Yes/No)
                std::cout << "What is the answer to that question you just provided?: " << question << "? (yes/no)\n";
                const bool answer2 = mesa::yes_no();
                
				// create a new tree node for the question the user just entered
                mesa::tree<std::string>* replacedTree = new mesa::tree<std::string> {};
                replacedTree->value = tree->value;
				tree->value = question;

                // if the answer to the new question is Yes, the new object is
                // on the right side of the tree
                if (answer2)
                {
                    mesa::tree<std::string>* newTree = new mesa::tree<std::string>{};
                    tree->left = replacedTree;
					tree->right = newTree;
					newTree->value = object;
                }
                
                // if the answer to the new question is No, the new object is
                // on the left side of the tree
                if (!answer2)
                {
                    mesa::tree<std::string>* newTree = new mesa::tree<std::string>{};
					tree->right = replacedTree;
					tree->left = newTree;
					newTree->value = object;
                }

                return tree;
            }
        }

        // if we have not reached a leaf node, ask the user the next question
        // and continue the game on the left or right side of the tree depending
        // on the user's answer
        std::cout << tree->value << " (yes/no)?\n";
        const bool answer3 = mesa::yes_no();

        
        // if the user answers Yes, continue the game on the right side of the tree
        if (answer3)
        {
			play_game(tree->right);

        }

        if (!answer3)
        {
            play_game(tree->left);
        }

        return tree;
    }
}