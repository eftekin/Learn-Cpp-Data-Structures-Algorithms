#include <iostream>
#include <string>

void asterisk(std::string word, std::string &text, int i)
{

    for (int k = 0; k < word.size(); ++k)
    {

        text[i + k] = '*';
    }
}

void bleep(std::string word, std::string &text)
{

    for (int i = 0; i < text.size(); ++i)
    {

        int match = 0;

        for (int j = 0; j < word.size(); ++j)
        {

            if (text[i + j] == word[j])
            {

                ++match;
            }
        }

        if (match == word.size())
        {

            asterisk(word, text, i);
        }
    }
}

int main()
{

    std::string word = "broccoli";

    std::string text = "I sometimes eat broccoli. There are three interesting things about broccoli. Number One. Nobody knows how to spell it. Number Two. No matter how long you boil it, it's always cold by the time it reaches your plate. Number Three. It's green. #broccoli";

    bleep(word, text);

    for (int i = 0; i < text.size(); i++)
    {

        std::cout << text[i];
    }

    std::cout << "\n";
}