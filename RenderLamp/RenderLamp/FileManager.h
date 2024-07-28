#pragma once
#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>

class FileManager {
public:
	bool IsThisPathExist(const std::string& name);
};