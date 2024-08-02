#include <iostream>
#include <vector>
#include <queue>

const int BOARD_SIZE = 8;
const int knightMoves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool isValidMove(int x, int y)
{
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

std::vector<std::vector<int>> knight_moves(std::vector<int> start, std::vector<int> end)
{
    std::vector<std::vector<int>> path;
    std::vector<std::vector<bool>> visited(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
    std::vector<std::vector<int>> parent(BOARD_SIZE * BOARD_SIZE, std::vector<int>(2, -1));
    std::queue<std::vector<int>> q;

    q.push(start);
    visited[start[0]][start[1]] = true;

    while (!q.empty())
    {
        std::vector<int> current = q.front();
        q.pop();

        if (current[0] == end[0] && current[1] == end[1])
        {
            std::vector<int> p = end;
            while (p != start)
            {
                path.push_back(p);
                int idx = p[0] * BOARD_SIZE + p[1];
                p = parent[idx];
            }
            path.push_back(start);

            std::vector<std::vector<int>> reversedPath;
            for (int i = path.size() - 1; i >= 0; --i)
            {
                reversedPath.push_back(path[i]);
            }
            return reversedPath;
        }

        for (int i = 0; i < 8; ++i)
        {
            int newX = current[0] + knightMoves[i][0];
            int newY = current[1] + knightMoves[i][1];

            if (isValidMove(newX, newY) && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                parent[newX * BOARD_SIZE + newY] = current;
                q.push({newX, newY});
            }
        }
    }

    return path;
}

int main()
{
    std::vector<int> start(2);
    std::vector<int> end(2);

    std::cout << "=> Enter the current Kight's location: ";
    std::cin >> start[0] >> start[1];

    std::cout << "=> Enter the destination location: ";
    std::cin >> end[0] >> end[1];

    std::vector<std::vector<int>> path = knight_moves(start, end);

    std::cout << "=> You made it in " << path.size() << " " << (path.size() > 1 ? "moves" : "move") << " ";
    std::cout << "from [" << start[0] << "," << start[1] << "] to [" << end[0] << "," << end[1] << "]! ";
    std::cout << "Here is your path:" << std::endl;

    for (const auto &pos : path)
    {
        std::cout << "      [" << pos[0] << "," << pos[1] << "]" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
