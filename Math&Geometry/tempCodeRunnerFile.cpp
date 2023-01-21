string addStrings(string &A, string &B)
    // {
    //     if (size(A) < size(B))
    //         return addStrings(B, A);
    //     int i = size(A) - 1, j = size(B) - 1, carry = 0, digit1, digit2, res;
    //     string ans = "";
    //     while (i >= 0)
    //     {
    //         digit1 = A[i--] - '0', digit2 = j > 0 ? (B[j--] - '0') : 0;
    //         res = digit1 + digit2 + carry;
    //         carry = res / 10;
    //         ans += res % 10 + '0';
    //     }
    //     if (carry)
    //         ans += carry + '0';
    //     reverse(begin(ans), end(ans));
    //     return ans;
    // }