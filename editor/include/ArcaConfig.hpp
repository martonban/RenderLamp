#ifndef ARCA_CONFIG_HPP
#define ARCA_CONFIG_HPP

class ArcaConfig {
    public:
        void Test();
};

#endif

inline void ArcaConfig::Test() {
    std::map<std::string, int> c_map { {"one", 1}, {"two", 2}, {"three", 3} };
    json j_map(c_map);

    std::ofstream file("output.json");
    if (file.is_open()) {
        file << j_map.dump(4); // Pretty print with an indent of 4 spaces
        file.close();
    }
}