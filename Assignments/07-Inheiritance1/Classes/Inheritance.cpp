#include "Inheritance.hpp"


/**
*  Objective: 
*   * You must implement the IFileOps interface, and ensure the following:
*     - It can open a file for reading, or writing, and will return true or false to indicate the operation's success
*     - writeFile should return true or false to indicate success, and write the contents of the provided string to
*       the current file opened (or false, if no file is currently open for writing).
*     - readFile should return either the contents of the file in a string, or an empty string (""), if the operation
*       fails.
*     - If a file is opened for reading, it should not be writable. Likewise, a file open for writing should fail read
*       requests.
*	* Finally, the function below should be implemented to return a shared_ptr containing an instance of your class 
*     that implements all required interfaces.
*/
std::shared_ptr<IFileOps> get_file_ops()
{
	return std::shared_ptr<IFileOps>();
}
