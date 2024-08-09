// problem link : 
class Solution {
public:
    string validIPAddress(const string& queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

private:
    bool isValidIPv4(const string& ip) {
        istringstream input(ip);
        string str;
        int num, count = 0;

        while (getline(input, str, '.')) {
            if (str.empty() || str.size() > 3 || !all_of(str.begin(), str.end(), ::isdigit)) {
                return false;
            }

            num = stoi(str);
            if (num < 0 || num > 255 || (str[0] == '0' && str.size() > 1)) {
                return false;
            }

            count++;
        }
        return count == 4 && ip.back() != '.';
    }

    bool isValidIPv6(const string& ip) {
        istringstream input(ip);
        string str;
        int count = 0;

        while (getline(input, str, ':')) {
            if (str.empty() || str.size() > 4) {
                return false;
            }

            for (char c : str) {
                if (!isxdigit(c)) {
                    return false;
                }
            }

            count++;
        }
        return count == 8 && ip.back() != ':';
    }
};