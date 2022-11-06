#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

typedef struct s_Lotto
{
	//managment 
	struct s_Lotto* next;
	struct s_Lotto* prev;

	//Data
	char Lottery_date[15];
	unsigned int Lottery_numbers;

}t_Lotto;

t_Lotto* Head = NULL;
t_Lotto* Tail = NULL;

//function specification
void addItem(char* date, unsigned int lotto_num);
void Parsing(char* file_name);
int dictionary(int num);

int main()
{
	Parsing("Lotto.txt");

	int num;
	char userResponse = '0';
	do {
		printf("Enter:\nN.Search Lottery Number - Get Its Date\nQ.Quit\n");
		scanf(" %c", &userResponse);
		switch (userResponse)
		{
		case 'N':
			printf("Input number between 1035 - 9934\n");
			scanf("%d", &num);
			dictionary(num);
			break;
		case 'Q':
			userResponse = '1';
			break;
		default:
			printf("Try Again\n");
			break;
		}

	} while (userResponse != '1');


	return 0;
}

void Parsing(char* file_name)
{
	FILE* f;
	f = fopen(file_name ,"r");
	if (!f)
	{
		//error 
		exit(1);
	}
	
	char Lottery_date[15];
	unsigned int Lottery_numbers;
	char* token;
	char getStr[1000];
	int i;
	fgets(getStr, 1000, f);
	char ret = "1";
	while (ret != NULL)
	{
		ret = fgets(getStr, 1000, f);
		if (ret == NULL)
		{
			break;
		}
		token = strtok(getStr, ",");
		Lottery_numbers = atoi(token);
		token = strtok(NULL, ",");
		strcpy(Lottery_date, token);

		addItem(Lottery_date, Lottery_numbers);
	}
}

void addItem(char* date, unsigned int lotto_num)
{
	t_Lotto* curr = (t_Lotto*)malloc(sizeof(t_Lotto));
	strcpy(curr->Lottery_date, date);
	curr->Lottery_numbers = lotto_num;
	if (curr == NULL)
	{
		//error
		exit(1);
	}

	if (Head == NULL)
	{
		Head = Tail = curr;
		curr->next = curr->prev = NULL;
	}
	else
	{
		Tail->next = curr;
		curr->prev = Tail;
		Tail = curr;
		curr->next = NULL;
	}

}

int dictionary(int num)
{
	t_Lotto* curr = Head;
	while (curr != NULL)
	{
		if (curr->Lottery_numbers == num)
		{
			printf("%s\n", curr->Lottery_date);
			return 1;
		}

		curr = curr->next;
	}
	printf("Lottery number not found\n");
	return 0;
}