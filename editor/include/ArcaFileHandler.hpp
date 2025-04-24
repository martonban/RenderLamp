#ifndef ARCA_FILE_HANDLER_HPP
#define ARCA_FILE_HANDLER_HPP

//-------------------------------------------------------------------------------------------------------------------------------                                          	
//												RenderLamp - ArcaFileHandler
//                                      	Copyright (c) Márton Bán 2025
//
//	These are the helper functions for Arca to handle files.
//-------------------------------------------------------------------------------------------------------------------------------

namespace CSVHandler {
// Fetch all strings from a CSV file
void FetchCSVData(const std::string& filePath, std::vector<std::string>& returnVector) {
    std::ifstream file(filePath);
    if (!std::filesystem::exists(filePath)) {
        std::cerr << "Error: The file does not exist! \n";
        return;
    }
    
    std::string temp;

    if(std::getline(file, temp, ';')) {
        returnVector.push_back(temp);
    }

    file.close();
}

};

namespace JSONHandler {

};


#endif