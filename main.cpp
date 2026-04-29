/* Program name: main.cpp
 * Author: Sahar Musleh
 * Date last updated: 4/28/2026
 * Purpose: Reads routing data, prompts the user for IPs, and displays routing path
 */

#include "graph.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

int main()
{
    Graph graph;
    std::ifstream file("routes.txt");

    if (!file)
    {
        std::cout << "Error opening routes.txt\n";
        return 1;
    }

    std::string line;

    // Regex patterns
    std::regex ipPattern(
        R"((\d{1,3}\.){3}\d{1,3})");
    std::regex adjacencyPattern(
        R"(^(\d+\s*)+$)");

    while (getline(file, line))
    {
        if (std::regex_match(line, ipPattern))
        {
            graph.addIP(line);
        }
        else if (std::regex_match(line, adjacencyPattern))
        {
            std::vector<int> edges;
            std::stringstream ss(line);
            int value;

            while (ss >> value)
                edges.push_back(value);

            graph.addAdjacency(edges);
        }
    }

    file.close();

    std::string startIP, goalIP;

    std::cout << "Enter the starting ip:\n";
    std::cin >> startIP;

    std::cout << "\nEnter the goal ip:\n";
    std::cin >> goalIP;

    std::cout << "\nFinding path from "
              << startIP << " to " << goalIP << "\n";

    std::vector<std::string> path =
        graph.findPath(startIP, goalIP);

    if (path.empty())
    {
        std::cout << "No path found\n";
    }
    else
    {
        for (size_t i = 0; i < path.size(); i++)
        {
            std::cout << path[i];
            if (i < path.size() - 1)
                std::cout << "-->";
        }
        std::cout << std::endl;
    }

    return 0;
}
