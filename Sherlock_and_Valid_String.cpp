/*************************************************************************************************************
**	Sherlock considers a string to be valid if all characters of the string appear the same number of times. 
**	It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times. Given a string , determine if it is valid. 
**	If so, return YES, otherwise return NO.
**/


#include <bits/stdc++.h>
#include <map>

using namespace std;

class HashMap
{
    std::map<char, int> m_hash;
    public:
    void add(char c)
    {
        auto it = m_hash.find(c);
        if(it != m_hash.end())
        {
            it->second += 1;
        }
        else
        {
            m_hash.insert(pair<char, int>(c, 1));
        }
    }
    int getMinFrequency()
    {
        int minFrequency = 999;
        for(auto it: m_hash)
        {
            if(it.second < minFrequency)
                minFrequency = it.second;
        }
        return minFrequency;
    }
    
    int getMaxFrequency()
    {
        int maxFrequency = 0;
        for(auto it: m_hash)
        {
            if(it.second > maxFrequency)
                maxFrequency = it.second;
        }
        return maxFrequency;
    }    
    
    int CharToDeleteToMatchFrequency(int pFrequency)
    {
        int numOfChar = 0;
        for(auto it: m_hash)
        {
            if(pFrequency > it.second)
            {
                numOfChar += (it.second);
            }
            else if(pFrequency < it.second)
            {
                numOfChar += (it.second - pFrequency);
            }
        }
        return numOfChar;
    }
    
    string GetStr()
    {
        stringstream ss;
        for(auto it: m_hash)
        {
            ss << it.first << ": " << it.second << endl;
        }
        return ss.str();
    }
};

string isValid(string s) 
{
    string toReturn = "NO";
    HashMap hm;

    int l = s.length();
    for(int i = 0; i < l; ++i)
    {
        hm.add(s[i]);
    }
    cout << "HashMap: " << endl;
    cout << hm.GetStr();
    
    int minF = hm.getMinFrequency();
    int maxF = hm.getMaxFrequency();
    
    cout << "[minF: " << minF << "] [maxF: " << maxF << "]"<< endl;
    
    int numOfCharToDelete = 0;
    for(int i = minF; i <= maxF; ++i)
    {
        numOfCharToDelete = hm.CharToDeleteToMatchFrequency(i);
        cout << "For Freq: "<< i << " char to delete: " << numOfCharToDelete << endl;
        if(numOfCharToDelete <= 1)
        {
            toReturn = "YES";
            break;
        }
    }    
    return toReturn;
}

int main()
{
    string s;
    getline(cin, s);
    string result = isValid(s);
    cout << result << endl;
	
    return 0;
}
