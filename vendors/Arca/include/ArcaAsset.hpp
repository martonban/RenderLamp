#ifndef ARCA_ASSET_HPP
#define ARCA_ASSET_HPP

#include <string>
#include <filesystem>
#include <map>
#include <memory>


class ArcaAsset {
    public:
        ArcaAsset(const std::filesystem::path& path);
        ArcaAsset(const std::filesystem::path& path, const std::string& fileName, const std::string& extension);
        void AddAssetReference(const std::string& key, const std::filesystem::path& assetPathReference);
        void AddStream(std::ostringstream& stream);
        bool DispatchAsset();
        bool LoadAssets();
        std::filesystem::path FetcReference(const std::string& key);
    private:
        std::filesystem::path PathBuilder(const std::filesystem::path& path, const std::string& fileName, const std::string& extension);
        std::filesystem::path mPath;
        std::map<std::string, std::filesystem::path> mReferenceMap;
    };

#endif 