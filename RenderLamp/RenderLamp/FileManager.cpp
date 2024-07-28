#include "FileManager.h"

// The path need to use '/' or '\\' insted of '\'
// TODO:  
bool FileManager::IsThisPathExist(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
