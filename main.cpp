#include <iostream>
#include <fstream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> loadingDone(false); // Flag to indicate loading is complete

void loadingAnimation() {
    const char animation[] = {'|', '/', '-', '\\'};
    int index = 0;

    while (!loadingDone) {
        std::cout << "\rLoading data... " << animation[index] << std::flush;
        index = (index + 1) % 4;
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Animation speed
    }

    std::cout << "\rLoading complete!       " << std::endl;
}

void readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        loadingDone = false; // Stop animation
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Simulate processing time for each line
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    file.close();
    loadingDone = true; // Signal that loading is done
}

int main() {
    
    return 0;
}
