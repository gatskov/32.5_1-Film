#include <iostream>
#include "nlohmann/json.hpp"
#include <map>
#include <fstream>

struct Film
{
    std::string name;
    std::map<std::string, std::string> actors;
    int year;
    std::string country;
    std::string studio;
    std::string director;
    std::string screenwriter;
    std::string producer;
};


int main() {
    std::cout << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --+\n";
    std::cout << "| 32.5 Practical Work.Task 1.Information about the film from the film portal |\n";
    std::cout << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --+\n\n";
    const std::string OUTPUT_PATH = "..\\films.json";
    std::cout << "Creating film data...\n";
    Film film;
    film.name = "Train station for two";
    film.actors = {{"waitress", "Lyudmila Gurchenko"}, {"pianist", "Oleg Basilashvili"}};
    film.year = 1982;
    film.country = "USSR";
    film.studio = "Mosfilm";
    film.director = "Lazarus Milkis";
    film.screenwriter = "Eldar Ryazanov";
    film.producer = "Nikita Mikhalkov";

    std::cout << "Opening file...\n";
    std::ofstream file(OUTPUT_PATH);
    if (file.is_open())
    {
        std::cout << "Writing to JSON file [" << OUTPUT_PATH << "]...\n";
        nlohmann::json dict;
        dict["name"] = film.name;
        dict["actors"] = film.actors;
        dict["year"] = film.year;
        dict["country"] = film.country;
        dict["studio"] = film.studio;
        dict["director"] = film.director;
        dict["screenwriter"] = film.screenwriter;
        dict["producer"] = film.producer;
        std::cout << "Writing is finished.\n";
        file << dict;
        file.close();
        std::cout << "File is closed.\n";
    }
    return 0;
}