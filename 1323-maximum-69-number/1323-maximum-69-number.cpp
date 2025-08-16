class Solution {
public:
    int maximum69Number (int num) {
       string num_str = to_string(num);
    
    for (char &ch : num_str) {
        if (ch == '6') {
            ch = '9'; // Change the first occurrence of '6' to '9'
            break; // Stop after the first change
        }
    }
    
    return stoi(num_str);
}

// Example test cases
int main() {
    cout << maximum69Number(9669) << endl; // Output: 9969
    cout << maximum69Number(9996) << endl; // Output: 9999
    cout << maximum69Number(9999) << endl; // Output: 9999
    return 0;
    

    }
};