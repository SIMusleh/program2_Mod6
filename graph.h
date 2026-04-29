/* Program name: graph.h
 * Author: Sahar Musleh
 * Date last updated: 4/28/2026
 * Purpose: Defines the Graph class used to store IP addresses and routing paths
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph
{
private:
    std::vector<std::string> ipAddresses;
    std::vector<std::vector<int>> adjacencyList;

public:
    void addIP(const std::string& ip);
    void addAdjacency(const std::vector<int>& edges);

    int getIPIndex(const std::string& ip) const;
    std::vector<std::string> findPath(const std::string& startIP,
                                      const std::string& endIP) const;
};

#endif
