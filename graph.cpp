/* Program name: graph.cpp
 * Author: Sahar Musleh
 * Date last updated: 4/28/2026
 * Purpose: Implements the Graph class methods including path finding
 */

#include "graph.h"
#include <queue>
#include <algorithm>

void Graph::addIP(const std::string& ip)
{
    ipAddresses.push_back(ip);
}

void Graph::addAdjacency(const std::vector<int>& edges)
{
    adjacencyList.push_back(edges);
}

int Graph::getIPIndex(const std::string& ip) const
{
    for (size_t i = 0; i < ipAddresses.size(); i++)
    {
        if (ipAddresses[i] == ip)
            return i;
    }
    return -1;
}

std::vector<std::string> Graph::findPath(const std::string& startIP,
                                         const std::string& endIP) const
{
    std::vector<std::string> path;

    int start = getIPIndex(startIP);
    int goal = getIPIndex(endIP);

    if (start == -1 || goal == -1)
        return path;

    std::vector<bool> visited(ipAddresses.size(), false);
    std::vector<int> parent(ipAddresses.size(), -1);

    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == goal)
            break;

        for (int neighbor : adjacencyList[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Reconstruct path
    for (int v = goal; v != -1; v = parent[v])
        path.push_back(ipAddresses[v]);

    std::reverse(path.begin(), path.end());
    return path;
}
