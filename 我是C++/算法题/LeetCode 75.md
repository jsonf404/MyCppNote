# LeetCode 75 刷题题解

[LeetCode 75 目录](https://leetcode.cn/studyplan/leetcode-75/)



## [交替合并字符串](https://leetcode.cn/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75)

1. **知识点**

- 考循环思路吧，没有什么好说的

---

2. **题解**

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    string res;
    int n = word1.size(), m = word2.size();

    for (int i = 0; i < n || i < m; i++) {
        if (i < n) res += word1[i];
        if (i < m) res += word2[i];
    }

    return res;
    }
};
```



## [字符串的最大公因子](https://leetcode.cn/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75)

1. **知识点**

- 字符串能同时除尽的简易判断条件：**左加右 = 右加左**
- 找最大公因数的函数 `gcd()` ，也可以用于找字符串最大公因数的长度

---

2. **题解**

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
        return "";

        int len=gcd(str1.size(),str2.size());
        return str1.substr(0,len);
    }
};
```



## [拥有最多糖果的孩子](https://leetcode.cn/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75)

1. **知识点**

- STL 算法的找最大数的函数：`auto max=max_element(vec.begin(),vec.end());` 。得到索引，解引用 `*max` 得到值。

---

2. **题解**

```cpp
class Solution{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       auto max=max_element(candies.begin(),candies.end());
       for(int& x:candies)
       {
        if(x+extraCandies>=*max)
        res.push_back(true);
        else
        res.push_back(false);
       }
    return res;
    }
    private:
    vector<bool> res;
};
```



## [种花问题](https://leetcode.cn/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75)

1. **知识点**

- 一个小贪心+数组扫描，能种的话自己为零且左右为零

---

2. **题解**

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) 
        {
            if (flowerbed[i] == 0) 
            {
                int left = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == size - 1) ? 0 : flowerbed[i + 1];

                if (left == 0 && right == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                    if (n <= 0) return true;
                }
            }
        }
        return n <= 0;
    }
};
```



## [反转字符串中的元音字母](https://leetcode.cn/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75)

1. **知识点**

- 左指针没有出现就右移，右指针没有出现就左移，都出现了证明可以互换了，直到左右相遇

---

2. **题解**

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (l < r) {
            if (!vowels.count(s[l])) {
                l++;
            } else if (!vowels.count(s[r])) {
                r--;
            } else {
                swap(s[l++], s[r--]);
            }
        }
        
        return s;
    }
};
```

