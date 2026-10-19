
class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string convert(int n) {
        if (n == 0)
            return "";

        if (n < 20)
            return below20[n];

        if (n < 100) {
            string result = tens[n / 10];
            if (n % 10 != 0)
                result += " " + convert(n % 10);
            return result;
        }

        string result = below20[n / 100] + " Hundred";

        if (n % 100 != 0)
            result += " " + convert(n % 100);

        return result;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<int> divisors = {
            1000000000, 1000000, 1000, 1
        };

        vector<string> units = {
            "Billion", "Million", "Thousand", ""
        };

        string result = "";

        for (int i = 0; i < 4; i++) {
            int group = num / divisors[i];

            if (group == 0)
                continue;

            if (!result.empty())
                result += " ";

            result += convert(group);

            if (!units[i].empty())
                result += " " + units[i];

            num %= divisors[i];
        }

        return result;
    }
};
