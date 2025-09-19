#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;  // rows x 26
    int rows;

    // Parse cell like "B12" -> (row, col)
    pair<int, int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1; // 1-indexed to 0-indexed
        return {row, col};
    }

    // Evaluate either integer or cell reference
    int evaluate(const string &token) {
        if (isdigit(token[0])) {
            return stoi(token);
        } else {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) : rows(rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        return evaluate(left) + evaluate(right);
    }
};
