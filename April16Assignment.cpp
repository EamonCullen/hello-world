#include "stdafx.h"
#include <stdio.h>


int countCharOccurence(char *string, char c);
int getOption();
int checkSpelling();
int findBestWord();
int findAllWords();
char randomLetters();

int nwords = 0;
char dictionary[80000][20];

void main(void)
{
	FILE *fptr;
	char fileName[] = "C:\\webster.txt";
	int option = 0;

	fptr = fopen(fileName, "r");

	if ( fptr  == NULL )
	{
		printf( "File could not be opened !!\n" );
		return;
	}
	else
	{
		while (!feof( fptr))
		{
			
			fscanf(fptr,"%s\n",dictionary[nwords]);
			nwords++;
		}
			fclose(fptr);
	}

	printf ("%ld words read from file \n\n", nwords);
			
	option = getOption();
	while (option != 0)
	{
	  randomLetters();
		if (option == 1) checkSpelling();
		if (option == 2) findBestWord();
		if (option == 3) findAllWords();
		if (option == 0) return;
		option = getOption();
	}
}

int getOption()
{
	int option = 0;

	puts("Options: 1=check spelling, 2=find longest word, 3=find all possible words, 0=quit\n");
	fflush(stdin);
	scanf("%d", &option);
	return option;
}

int checkSpelling()
{
	int i=0;
	char temp[20];

	puts ("Enter word to check");
	fflush(stdin);
	gets (temp);

	for (i=0;i<nwords;i++)
	{
		if (!strcmp(temp,dictionary[i]))
		{
			puts("Spelling Correct!");
			return 1;
		}
	}
	puts("Word not found");
	return 0;
}

char randomLetters() {

    char type, letters[10] = { };
    char vowels[6] = { 'A', 'E', 'I', 'O', 'U' };
    char consonants[21] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z' };
    int i, k, v, l, c;

    for (i = 0; i < 9; i++) {
        printf("Vowel or consonant? (V/C)\n");
        scanf(" %c", &type);

        if (type == 'V')
            for (k = 0; k<1; k++) {
                v = (rand() % 5);
                letters[i] = vowels[v];
                break;


            }
        if (type == 'C')
            for (l = 0; l<1; l++) {
                c = (rand() % 21);
                letters[i] = consonants[c];
                break;

            }
    }

    return("%s", letters);
}

int findAllWords()
{
	char temp[20] = randomLetters();
	int numMatches = 0;
	int highestMatch = 0;
	int i=0, j=0, len=0;
	int tempCount=0, wordCount=0;

	puts("\nMatching Words:\n--------------------------");

	for (i=0;i<nwords;i++)
	{
		numMatches = 0;
		len = strlen(dictionary[i]);
		
		for (j=0;j<len;j++)
		{
			tempCount = 0;
			wordCount = 0;
			tempCount = countCharOccurence(temp, dictionary[i][j]);
			wordCount = countCharOccurence(dictionary[i], dictionary[i][j]);

			if ((tempCount > 0) && (tempCount == wordCount))
			{
				numMatches = numMatches + 1;
			}
			else
			{
				numMatches = 0;
				break;
			}
		}
		
		if (numMatches == len)
		{
			printf ("%s\n", dictionary[i]);
		}
	}

	

	return numMatches;
}

int findBestWord()
{
	char bestFit[20];
	int numMatches = 0;
	int highestMatch = 0;
	int i=0, j=0, len=0;
	char temp[20] = randomLetters();

	int tempCount=0, wordCount=0;

	for (i=0;i<nwords;i++)
	{
		numMatches = 0;
		len = strlen(dictionary[i]);
		
		for (j=0;j<len;j++)
		{
			tempCount = 0;
			wordCount = 0;
			tempCount = countCharOccurence(temp, dictionary[i][j]);
			wordCount = countCharOccurence(dictionary[i], dictionary[i][j]);

			if ((tempCount > 0) && (tempCount == wordCount))
			{
				numMatches = numMatches + 1;
			}
			else
			{
				numMatches = 0;
				break;
			}
		}

		if (numMatches > highestMatch)
		{
			strcpy(bestFit, dictionary[i]);
			highestMatch = numMatches;
		}
	}

	printf ("Best Fit for \"%s\" is \"%s\"  [%d]\n", temp, bestFit, highestMatch);

	return numMatches;
}


int countCharOccurence(char *string, char c)
{
	int i=0,count=0,len=0;
	len = strlen(string);
	for(i=0;i<len;i++)
	{
		if (string[i] == c) count++;
	}
	return count;
}
