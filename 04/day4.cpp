#include <iostream>
#include <unordered_set>
#include <vector>

// Just a brute force approach...
int part_one(const std::vector<std::string>& board)
{
    size_t            ans = 0;
    const std::string f   = "XMAS";
    const std::string b   = "SAMX";
    // Slide over a 4x4 grid, check all directions within
    for(size_t i = 0; i < board.size() - 3; i++)
    {
        for(size_t j = 0; j < board[i].size() - 3; j++)
        {
            // Check diagonals '/' and '\'
            std::string fwd
                = board[i + 3][j] + board[i + 2][j + 1] + board[i + 1][j + 2] + board[i][j + 3];
            std::string bwd
                = board[i][j] + board[i + 1][j + 1] + board[i + 2][j + 2] + board[i + 3][j + 3];
            // Check row/col
            std::string row = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
            std::string col = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];

            if(fwd == f || bwd == f || row == f || col == f)
                ans++;
            else if(fwd == b || bwd == b || row == b || col == b)
                ans++;
        }
    }

    return ans;
}

int main
{
    // Get input into vector where index is line #
    std::vector<std::string> board;
    std::string              tmp;
    while(std::cin >> tmp)
        board.push_back(tmp);

    std::cout << part_one(board);
    return 0;
}
