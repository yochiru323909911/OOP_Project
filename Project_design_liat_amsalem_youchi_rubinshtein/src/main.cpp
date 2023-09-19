#include "Controller.h"
#include "FileExceptions.h"

//=================================================================================================
int main()
{
	try
	{
		Controller control;
		control.run();
	}
	catch (FileExceptions& fileExceptions)
	{
		fileExceptions.handleException();
		return EXIT_FAILURE;
	}
	catch (std::exception& wrongInputMaxAction)
	{
		std::cerr << wrongInputMaxAction.what();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
