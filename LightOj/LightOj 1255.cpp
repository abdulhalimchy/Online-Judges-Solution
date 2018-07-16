/*...................Allah is almighty*.................*/
///.....................LightOj-1255...................///

#include<bits/stdc++.h>
#define MX 1000000
using namespace std;

int lps[MX]; //"Length of the largest proper prefix which is suffix also for 0 to MX length prefix" or "Faliure Table"
int co=0;
//Generate largest proper prefix which is suffix also, for every prefix of the pattern string
void generate_lps(string pattern, int lengthOfthepattern)
{
    lps[0]=0, lps[1]=0;
    for(int i=2; i<=lengthOfthepattern; i++)//i is the length of the prefix string
    {
        int j=lps[i-1];
        while(true){
            lps[i]=0; // for memset the lps[]
            if(pattern[j]==pattern[i-1])
            {
                lps[i]=j+1;
                break;
            }
            if(j==0)
            {
                lps[i]=0;
                break;
            }

                j=lps[j];
        }
    }
}


void kmp(string text, string pattern, int textSize, int patternSize){

    generate_lps(pattern, patternSize); // Generate lps array

    int i=0; // index of text
    int j=0; // index of pattern

    while(true)
    {
        if(i==textSize)
            break;
        if(text[i]==pattern[j])
        {
            i++; //next character of the text
            j++; //next character of the pattern;
            if(j==patternSize)
            {
                co++;
                j=lps[j];
            }
        }
        else
        {
            if(j==0) // when j=0, we have to start comparing again from  beginning of the pattern
                i++; // next character of the text
            else
                j=lps[j]; // next index of the already matched characters of the pattern string
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        string pattern, text;
        cin >> text >> pattern;
        int n=text.size(), m=pattern.size();
        //memset(lps, 0, sizeof(lps));
        co=0;
        kmp(text, pattern, n, m);
        cout << "Case " << i << ": " << co << endl;
    }

    return 0;
}

