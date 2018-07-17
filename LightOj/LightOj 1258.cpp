/*...................Allah is almighty*.................*/

///-----LightOj::1258 (Using KMP algorthm)----///
/*
    Given,    text       = bababababa
            pattern      = ababababab       //(reversed of 'text')

    Now, figure out the largest substrings matched

    text    = bababababa_
    pattern = _ababababab           //largest matched ababababa (size=9);

    Now, to make the string palindrome,
    we have to add total numbers character =(textSize-largestMatchedSubstringSize)=(10-9)=1;
    Finally, the palindrome or resulting string length=11;
*/

#include<bits/stdc++.h>
#define MX 1000005
using namespace std;

int lps[MX]; //"Length of the largest proper prefix which is suffix also for 0 to MX length prefix" or "Faliure Table"
int co; // counting the total matched character

//Generate largest proper prefix which is suffix also, for every prefix of the pattern string
void generate_lps(string pattern, int patternSize)
{
	int i=1, j=0;
	lps[0]=-1, lps[1]=0;

	while(i<patternSize)
    {
        while(j>=0 && pattern[i]!=pattern[j])
        {
            j=lps[j];
        }
        i++, j++;
        lps[i]=j;
    }
}

void kmp(string text, string pattern, int textSize, int patternSize)
{
    generate_lps(pattern, patternSize);
    int i=0, j=0;

    while(i<textSize)
    {
        while(j>=0 && pattern[j]!=text[i])
        {
            j=lps[j];
        }
        i++, j++;
    }
    co=j;
}

void reverse_string(string &str, int sizeOfstr)
{
    int sz=sizeOfstr/2;
    for(int i=0, j=sizeOfstr-1; i<sz; i++, j--)
    {
        swap(str[i],str[j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        string text, pattern;
        cin >> text;
        int sz=text.size();
        //cout << sz << endl;
        pattern=text;
        reverse_string(pattern, sz);
        co=0;
        kmp(text, pattern, sz, sz);
        cout << "Case " << i << ": " << sz+(sz-co) << endl;
    }

    return 0;
}
