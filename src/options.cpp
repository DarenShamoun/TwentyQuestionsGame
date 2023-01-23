//Daren Shamoun
#include "options.h"
#include <iostream>
#include <algorithm>

namespace mesa
{
	//displays the possible command line arguements
	std::string usage(const char* argv)
	{
		const std::string input(argv);
		std::string usage = "Usage: " + input + " [-h] [-f <filename>]\n";

		return usage;
	}

	//displays the full help text along with the file name
	std::string help(const char* argv)
	{
		std::string helpText = usage(argv) + "\n-h: Displays the help text and exits." +
			"\n-f <filename>: Loads the game tree from the specified file.\n";

		return helpText;
	}

	//parses the command line arguements and returns the users desired settings
	mesa::option get_options(int argc, char** argv)
	{
		mesa::option userOptions {};

		//loops through each arguement
		for (auto i = 0; i < argc; i++)
		{
			//if found displays help text
			if (std::strcmp(argv[i], "-h") == 0)
			{
				std::cout << help(argv[i]) << '\n';
				exit(0);
			}

			//if found sets the file name
			if (std::strcmp(argv[i], "-f") == 0)
			{
				if (i + 1 >= argc)
				{
					// display an error message if no filename was specified
					std::cout << "Invalid entry! (-f)\n";
					std::cout << "No filename specified after -f option!\n";
					exit(0);
				}

				// store the filename specified after the -f option
				userOptions.filename = argv[i + 1];
				userOptions.load = true;
			}
		}
		return userOptions;
	}
}
