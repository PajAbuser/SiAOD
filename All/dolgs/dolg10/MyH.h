#ifndef DOLG10_MYH_H
#define DOLG10_MYH_H

#include <bits/stdc++.h>

using namespace std;

int cmp = 0;

int* get_prefix(string str) {
    int str_size = str.length();
    int* pf = new int[str_size];
    pf[0] = 0;
    cmp++;
    for (int i = 1; i < str_size; i++) {
        int j = pf[i - 1];
        cmp += 2;
        while ((j > 0) && (str[i] != str[j]))
            j = pf[j - 1];
        cmp++;
        if (str[i] == str[j])
            j++;
        pf[i] = j;
        cmp++;
    }
    return pf;
}

int KMP_search(string text, string pattern) {
    string str = pattern + "$" + text;
    int* pf = get_prefix(str);
    int str_size = str.length();
    int pattern_size = pattern.length();
    int num = 0;
    cmp++;
    for (int i = pattern_size + 1; i < str_size; i++) {
        cmp++;
        if (pf[i] == pattern_size)
            num++;
        cmp++;
    }
    delete[] pf;
    return num;
}

void color_check(std::string text) {
    std::regex colorPattern = std::regex("\"(?!#([0-9a-fA-F]{6}|[0-9a-fA-F]{3})\")\\S+");
    std::smatch m;
    while (std::regex_search(text, m, colorPattern)) {
        std::cout << m[0].str() << std::endl;
        text = m.suffix();

    }
}

#endif //DOLG10_MYH_H
