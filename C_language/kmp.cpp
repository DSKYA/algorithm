#include "stdafx.h"
#include <iostream>
#include <istream>
#include <string>

using namespace std;
const int MAX_LENGTH = 30;

void usage();

class KMPmatch
{
public:
    KMPmatch();
    KMPmatch(string kmptext,string kmppattern);
    ~KMPmatch();

    void setText(string kmptext);
    void setPattern(string kmppattern);
    void getnext();
    int kmpIndex();
private:
    string text;
    string pattern;
    int next[MAX_LENGTH];
    int text_number;
    int pattern_number;
};

KMPmatch::KMPmatch()
{
    text = "";
    pattern = "";
    text_number = 0;
    pattern_number = 0;
}

KMPmatch::KMPmatch(string kmptext,string kmppattern)
{
    text = kmptext;
    text_number = strlen(kmptext.c_str());
    pattern = kmppattern;
    pattern_number = strlen(kmppattern.c_str());
}
KMPmatch::~KMPmatch()
{}

void KMPmatch::setPattern(string kmppattern)
{
    cout << "Setting the new pattern..." << endl;
    pattern = kmppattern;
    pattern_number = strlen(kmppattern.c_str());
    cout << "Done!" << endl;
}

void KMPmatch::setText(string kmptext)
{
    cout << "Setting the new text..." << endl;
    text = kmptext;
    text_number = strlen(kmptext.c_str());
    cout << "Done!" << endl;
}

void KMPmatch::getnext()
{
    next[0] = 0;
    int i = 1, j = 0;
    while (i < pattern_number)
    {
        if (text[i] == text[j])
        {
            next[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = next[j - 1];
        }
        else
            next[i] = 0;
        i++;
    }
}

int KMPmatch::kmpIndex()
{
    cout << "Matching..." << endl;
    getnext();
    int i = 0, j = 0;
    while (i < text_number)
    {
        if (text[i] == pattern[j])
        {
            if (j == pattern_number - 1)
            {
                cout << "Find the pattern string in the " << i-j+1 << "th place..." << endl;
                return i - j+1;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j > 0)
            {
                j = next[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    cout << "Oops! No match..." << endl;
    return -1;
}

void usage()
{
    cout << "Try KMP matching system..." << endl;
    cout << "Enter '1' to input the text and pattern..." << endl;
    cout << "Enter '2' to change the text..." << endl;
    cout << "Enter '3' to change the pattern..." << endl;
    cout << "Enter '4' to start match..." << endl;
    cout << "Enter 'q' to quit the program..." << endl;
}

int main()
{
    string text, pattern;

    while(true) {
        usage();

        char op = getchar();
        switch (op) {
            case '1':
                cout << "Input string to be matched...: " << endl;
                getline(cin, text);
                cout << "Input pattern string: " << endl;
                getline(cin, pattern);
                KMPmatch match(text, pattern);
                break;
            case '2':
                cout << "Input the new text..." << endl;
                match.setText(text);
            case '3':
                cout << "Input the new pattern..." << endl;
                match.setPattern(pattern);
            case '4':
                match.kmpIndex();
            case 'q':
                exit(0);
            default:
                break;
        }
    }
}
