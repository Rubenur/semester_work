#include"checking_input.h"

bool checking_input(int params_count, std::string params[])
{
	int temp_brackets = 0, temp_reverse_brackets = 0;
	for (int i = 0; i < params_count; i++)
	{
		//extra space
		/*
		if (params[i].size() == 0)
		{
			std::cout << std::endl;
			std::cout << "Input error!" << std::endl;
			std::cout << "You have entered an extra space." << std::endl;
			if (i == 0)
			{
				std::cout << "Before" << params[i + 1] << std::endl;
			}
			if (i == params_count - 1)
			{
				std::cout << "After " << params[i - 1] << std::endl;
			}
			if ((i != params_count - 1) && (i != 0))
			{
				std::cout << "Between " << params[i-1] << " and " << params[i+1] << std::endl;
			}
			return false;
		}
		*/
		//Unknown character
		if ((params[i].size() == 1) && (params[i].find_first_not_of("0123456789/*-+^()", 0) != std::string::npos))
		{
			std::cout << std::endl;
			std::cout << "Input error!" << std::endl;
			std::cout << "Unknown character: ";
			std::cout << params[i] << std::endl;
			return false;
		}

		//The number
		if (params[i].find_first_of("-.0123456789", 0) != std::string::npos)
		{
			int temp_point = 0;
			for (int j = 0; j < params[i].size(); j++)
			{
				if (params[i][j] == '.' )
				{
					temp_point++;
				}
				if ((params[i][j] == '-') && (j != 0))
				{
					std::cout << std::endl;
					std::cout << "Input error!" << std::endl;
					std::cout << "The number is written incorrectly: ";
					std::cout << params[i] << std::endl;
					return false;
				}
			}

			if (temp_point > 1)
			{
				std::cout << std::endl;
				std::cout << "Input error!" << std::endl;
				std::cout << "The number is written incorrectly: ";
				std::cout << params[i] << std::endl;
				return false;
			}

			if ((params[i][0] == '.') && (params[i][params[i].size()] == '.'))
			{
				std::cout << std::endl;
				std::cout << "Input error!" << std::endl;
				std::cout << "The number is written incorrectly: ";
				std::cout << params[i] << std::endl;
				return false;
			}

			if ((params[i][0] == '-') && (params[i].size() != 1))
			{
				if (params[i].find_first_not_of(".0123456789", 0) != std::string::npos)
				{
					std::cout << std::endl;
					std::cout << "Input error!" << std::endl;
					std::cout << "The number is written incorrectly: ";
					std::cout << params[i] << std::endl;
					return false;
				}
				if (params[i][1] == '.')
				{
					std::cout << std::endl;
					std::cout << "Input error!" << std::endl;
					std::cout << "The number is written incorrectly: ";
					std::cout << params[i] << std::endl;
					return false;
				}
			}
		}

		//functions
		if (params[i].find_first_of("abcdefghijklmnopqrstuvwxyz", 0) != std::string::npos)
		{
			if (params[i].compare("sin") != 0 &&
				params[i].compare("cos") != 0 &&
				params[i].compare("tg") != 0 &&
				params[i].compare("ctg") != 0 &&
				params[i].compare("ln") != 0 &&
				params[i].compare("log") != 0 &&
				params[i].compare("sqrt") != 0 &&
				params[i].compare("pi") != 0 &&
				params[i].compare("exp") != 0 &&
				params[i].compare("abs") != 0)
			{
				std::cout << std::endl;
				std::cout << "Input error!" << std::endl;
				std::cout << "Error in writing the function: ";
				std::cout << params[i] << std::endl;
				return false;
			}
		}

		//The brackets 
		if ((params[i].size() == 1) && (params[i].find_first_of("(", 0) != std::string::npos))
		{
			temp_brackets++;
		}
		if ((params[i].size() == 1) && (params[i].find_first_of(")", 0) != std::string::npos))
		{
			temp_reverse_brackets++;
		}
	}
	if (temp_brackets != temp_reverse_brackets)
	{
		std::cout << std::endl;
		std::cout << "Input error!" << std::endl;
		std::cout << "The brackets are placed incorrectly." << std::endl;
		return false;
	}
    return true;
}