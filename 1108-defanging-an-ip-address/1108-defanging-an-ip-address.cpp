class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();

        stringstream ss(address);
        string a = "";
        string b = "";
        string c = "";
        string d = "";

        getline(ss,a,'.');
        getline(ss,b,'.');
        getline(ss,c,'.');
        getline(ss,d,'.');

        string ans = a + "[.]" + b + "[.]" + c + "[.]" + d;

        return ans;
    }
};