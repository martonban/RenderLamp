#ifndef ARCA_ASSET_HPP
#define ARCA_ASSET_HPP

#include <string>
#include <filesystem>
#include <map>
#include <memory>

class ArcaAsset {
    public:
        // ArcaAsset Constractors 
        ArcaAsset(const std::filesystem::path& path);
        ArcaAsset(const std::filesystem::path& path, const std::string& fileName, const std::string& extension);

        // Stream Based output asset
        void AddSingleStreamAndDispatch(std::ostringstream& stream);

        // Arca Archive  
        

        

    private:
        std::filesystem::path PathBuilder(const std::filesystem::path& path, const std::string& fileName, const std::string& extension);
        std::filesystem::path mPath;

    };

#endif 