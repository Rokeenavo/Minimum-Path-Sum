#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();

                                                                    // Создаем дополнительную матрицу для хранения минимальных сумм путей
    vector<vector<int>> dp(m, vector<int>(n, 0));

                                                                     // Заполняем первый элемент дополнительной матрицы
    dp[0][0] = grid[0][0];

                                                                    // Заполняем первую строку дополнительной матрицы
    for (int j = 1; j < n; ++j) 
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

                                                                    // Заполняем первый столбец дополнительной матрицы
    for (int i = 1; i < m; ++i) 
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

                                                                    // Заполняем остальные элементы дополнительной матрицы
    for (int i = 1; i < m; ++i) 
    {
        for (int j = 1; j < n; ++j) 
        {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

                                                                       // Возвращаем значение в правом нижнем углу дополнительной матрицы
    return dp[m - 1][n - 1];
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    vector<vector<int>> grid = 
    {
        {1, 3, 12},
        {3, 5, 3},
        {4, 2, 1}
    };

    int result = minPathSum(grid);
    cout << "Минимальная сумма пути: " << result << endl;

    return 0;
}



