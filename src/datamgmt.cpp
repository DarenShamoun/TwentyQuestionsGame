//Daren Shamoun
#include "datamgmt.h"

namespace mesa
{
    //takes the input from the user until a newline character
    std::string get_user_input()
    {
        std::string input;
        std::getline(std::cin, input);

        bool hasLetter = false;
        for (const char c : input)
        {
            if (bool(isalpha(c)))
            {
                hasLetter = true;
            }
        }

        if (hasLetter && input != "")
        {
            return input;
        }

        std::cout << "Invalid entry! Try again.\n";
        return get_user_input();
    }
    
    //ask yes or no questions
    bool yes_no()
    {
        std::string answer = mesa::get_user_input();
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "yes" || answer == "y")
        {
            return true;
        }

        if (answer == "no" || answer == "n")
        {
            return false;
        }
        
        // display an error message if not yes or no
        std::cout << "Invalid entry! Try again.\n";
        return yes_no();
    }


    //saves the game state
    void save_game(mesa::tree<std::string>* tree, std::ofstream& output)
    {
        if (tree == nullptr)
        {
            return;
        }

        // if we have reached a leaf node, write the value to the file
        if (tree->left == nullptr && tree->right == nullptr)
        {
            output.write("A:", 2); // write an "A" character to indicate an answer node
        }
        else
        {
            output.write("Q:", 2); // write a "Q" character to indicate a question node
        }
        
        // if we have not reached a leaf node, write the question to the file
        // and continue the traversal on the left and right sides of the tree
        output.write(tree->value.c_str(), static_cast<std::streamsize>(tree->value.length()));
        output.write("\n", 1);
        
        save_game(tree->left, output); // save the left subtree
        save_game(tree->right, output); // save the right subtree
    }

    // function to read data from the "data.txt" file and update the binary tree
    mesa::tree<std::string>* read_data(std::ifstream& inputStream)
    {
        // read the first line of the file
        std::string line;
        std::getline(inputStream, line);
        
        mesa::tree<std::string>* node = new mesa::tree<std::string>{};

        // check if the line is a question or an answer
        if (line[0] == 'Q')
        {
            // if it is a question, create a new tree node with the question as the value
            node->value = line.substr(2);

            // read the next line of the file and recursively create the left and right subtrees
            node->left = mesa::read_data(inputStream);
            node->right = mesa::read_data(inputStream);
        }
        else if (line[0] == 'A')
        {
            // if it is an answer, create a new tree node with the answer as the value
            node->value = line.substr(2);
        }

        // return a pointer to the root if the end of the file has been reached
        return node;
    }

    mesa::tree<std::string>* initialize_tree(mesa::option& userOptions, std::ifstream& inputStream)
    {
        // initialize the game tree
        mesa::tree<std::string>* root;

        // read the data from the file
        root = mesa::read_data(inputStream);

        // check if the data was successfully read
        if (root == nullptr)
        {
            // display an error message if the file was empty or the data could not be read
            std::cerr << "Error: failed to read data from file '" << userOptions.filename << "'\n";
        }
        return root;
    }

    // deletes the tree pointed to by tree and all of its descendants
    void delete_tree(mesa::tree<std::string>* tree)
    {
        // if the tree is not empty, delete its children recursively
        if (tree == nullptr)
        {
            return;
        }
        
        // recursively delete the left and right subtrees
        mesa::delete_tree(tree->left);
        mesa::delete_tree(tree->right);
        
		// delete the current node
		delete tree;
    }
}