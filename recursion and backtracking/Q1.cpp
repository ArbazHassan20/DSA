#include <iostream>
#include <vector>
using namespace std;

// Function to check if the current position is valid
bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n; // Valid if within the matrix boundaries
}

// Function to find all possible paths from (0,0) to (n-1,n-1)
void total(vector<vector<int>> &matrix, int i, int j, int n, string &path, vector<string> &ans, vector<vector<bool>> &visited)
{
    if (i == n - 1 && j == n - 1)
    { 
        
        ans.push_back(path);
        return;
    }

    visited[i][j] = true; 
    // Move Up
    if (valid(i - 1, j, n) && matrix[i - 1][j] && !visited[i - 1][j])
    {
        path.push_back('U');
        total(matrix, i - 1, j, n, path, ans, visited);
        path.pop_back(); 
    }

    // Move Down
    if (valid(i + 1, j, n) && matrix[i + 1][j] && !visited[i + 1][j])
    {
        path.push_back('D');
        total(matrix, i + 1, j, n, path, ans, visited);
        path.pop_back(); }

    // Move Left
    if (valid(i, j - 1, n) && matrix[i][j - 1] && !visited[i][j - 1])
    {
        path.push_back('L');
        total(matrix, i, j - 1, n, path, ans, visited);
        path.pop_back(); 
    }

    // Move Right
    if (valid(i, j + 1, n) && matrix[i][j + 1] && !visited[i][j + 1])
    {
        path.push_back('R');
        total(matrix, i, j + 1, n, path, ans, visited);
        path.pop_back();
    }

    visited[i][j] = false; 
}

// Function to initiate finding all paths from start to end
vector<string> findAllPaths(vector<vector<int>> &matrix, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    // Start only if the starting cell is passable (1)
    if (matrix[0][0] == 1)
    {
        total(matrix, 0, 0, n, path, ans, visited);
    }

    return ans;
}

int main()
{
    // Define a 4x4 matrix 
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};

    int n = matrix.size(); // Get the size of the matrix (n x n)
    vector<string> paths = findAllPaths(matrix, n);

    if (paths.empty())
    {
        cout << "No path found." << endl;
    }
    else
    {
        // Output all the found paths
        cout << "Found paths: \n";
        for (int i = 0; i < paths.size(); i++)
        {
            cout << paths[i] << endl;
        }
    }

    return 0;
}
