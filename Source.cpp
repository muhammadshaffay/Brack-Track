#include <iostream>
using namespace std;

bool paranthesis(string);
int excess(string);

int main()
{
	string sentence = "[[][]][]";

	int result1 = paranthesis(sentence);

	if (result1 == 0)
		cout << "False" << endl;

	else if (result1 == 1)
		cout << "True" << endl;

	int i = excess(sentence);
	
	if (i == -1)
		cout << "\n\nNo Error found!!";
	else
		cout << "\n\nError At Index : " <<  i << endl;
		
	return 0;
}

bool paranthesis(string sentence)
{
	const int len = sentence.length();
	char *recorder  = new char[len];

	int left_bracket_round = 0;
	int right_bracket_round = 0;
	int left_bracket_square = 0;
	int right_bracket_square = 0;
	int left_bracket_curly = 0;
	int right_bracket_curly = 0;

	// If 1st Or Last Index
	if (sentence[0] == ')' | sentence[0] == ']' | sentence[0] == '}') // For 1st Index
		return false;

	else if (sentence[len - 1] == '(' | sentence[len - 1] == '[' | sentence[len - 1] == '{') // For Last Index
		return false;

	else
	{
		int counter = 0;
		for (int i = 0; i < len; i++)
		{
			if (sentence[i] == '(')
				recorder[counter++] = '(';

			else if (sentence[i] == ')')
				recorder[counter++] = ')';

			else if (sentence[i] == '[')
				recorder[counter++] = '[';

			else if (sentence[i] == ']')
				recorder[counter++] = ']';

			else if (sentence[i] == '{')
				recorder[counter++] = '{';

			else if (sentence[i] == '}')
				recorder[counter++] = '}';
		}

		for (int i = 0; i < counter; i++)
		{
			if (recorder[i] == ')') // If Right Bracket
			{
				int count_0 = left_bracket_round;
				int count_1 = right_bracket_round;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '(')
						count_0 += 1;

					else if (recorder[j] == ')')
						count_1 += 1;
				}
				right_bracket_round += 1;
				
				if (count_0 < count_1)
					return false;
			}
			else if (recorder[i] == '(') // If Left Bracket
			{

				int count_0 = left_bracket_round;
				int count_1 = right_bracket_round;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '(')
						count_0 += 1;
					else if (recorder[j] == ')')
						count_1 += 1;
				}

				left_bracket_round += 1;

				if (count_0 > count_1)
					return false;

			}
			else if (recorder[i] == ']') // If Right Bracket
			{
				int count_0 = left_bracket_square;
				int count_1 = right_bracket_square;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '[')
						count_0 += 1;

					else if (recorder[j] == ']')
						count_1 += 1;
				}
				right_bracket_square += 1;
				
				if (count_0 < count_1)
					return false;
			}
			else if (recorder[i] == '[') // If Left Bracket
			{

				int count_0 = left_bracket_square;
				int count_1 = right_bracket_square;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '[')
						count_0 += 1;
					else if (recorder[j] == ']')
						count_1 += 1;
				}

				left_bracket_square += 1;

				if (count_0 > count_1)
					return false;

			}
			else if (recorder[i] == '}') // If Right Bracket
			{
				int count_0 = left_bracket_curly;
				int count_1 = right_bracket_curly;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '{')
						count_0 += 1;

					else if (recorder[j] == '}')
						count_1 += 1;
				}
				right_bracket_curly += 1;
				
				if (count_0 < count_1)
					return false;
			}
			else if (recorder[i] == '{') // If Left Bracket
			{

				int count_0 = left_bracket_curly;
				int count_1 = right_bracket_curly;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '{')
						count_0 += 1;
					else if (recorder[j] == '}')

						count_1 += 1;
				}

				left_bracket_curly += 1;

				if (count_0 > count_1)
					return false;

			}
		}
	}
	return true; // If No Error
}

int excess(string sentence)
{
	int ultimate = 0;
	int *ptr = new int[100];
	const int len = sentence.length();
	char* recorder = new char[len];

	int left_bracket_round = 0;
	int right_bracket_round = 0;
	int left_bracket_square = 0;
	int right_bracket_square = 0;
	int left_bracket_curly = 0;
	int right_bracket_curly = 0;

	// If 1st Or Last Index
	if (sentence[0] == ')' | sentence[0] == ']' | sentence[0] == '}') // For 1st Index
		return 0;

	else if (sentence[len - 1] == '(' | sentence[len - 1] == '[' | sentence[len - 1] == '{') // For Last Index
		return len - 1;

	else
	{
		int counter = 0;
		for (int i = 0; i < len; i++)
		{
			if (sentence[i] == '(')
				recorder[counter++] = '(';

			else if (sentence[i] == ')')
				recorder[counter++] = ')';

			else if (sentence[i] == '[')
				recorder[counter++] = '[';

			else if (sentence[i] == ']')
				recorder[counter++] = ']';

			else if (sentence[i] == '{')
				recorder[counter++] = '{';

			else if (sentence[i] == '}')
				recorder[counter++] = '}';
		}

		for (int i = 0; i < counter; i++)
			cout << recorder[i];

		for (int i = 0; i < counter; i++)
		{
			if (recorder[i] == ')') // If Right Bracket
			{
				int count_0 = left_bracket_round;
				int count_1 = right_bracket_round;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '(')
						count_0 += 1;

					else if (recorder[j] == ')')
						count_1 += 1;
				}
				right_bracket_round += 1;
				
				if (count_0 < count_1)
					return i;
			}
			else if (recorder[i] == '(') // If Left Bracket
			{

				int count_0 = left_bracket_round;
				int count_1 = right_bracket_round;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '(')
					{
						count_0 += 1;
						ptr[ultimate] = j;
						ultimate++;
					}
					else if (recorder[j] == ')')
					{
						count_1 += 1;
						ultimate--;
					}
				}

				left_bracket_round += 1;

				if (count_0 > count_1)
					return ptr[0];

			}
			else if (recorder[i] == ']') // If Right Bracket
			{
				int count_0 = left_bracket_square;
				int count_1 = right_bracket_square;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '[')
						count_0 += 1;
					else if (recorder[j] == ']')
						count_1 += 1;
				}
				right_bracket_square += 1;
				
				if (count_0 < count_1)
					return i;
			}
			else if (recorder[i] == '[') // If Left Bracket
			{

				int count_0 = left_bracket_square;
				int count_1 = right_bracket_square;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '[')
					{
						count_0 += 1;
						ptr[ultimate] = j;
						ultimate++;
					}
					else if (recorder[j] == ']')
					{
						count_1 += 1;
						ultimate--;
					}
				}

				left_bracket_square += 1;

				if (count_0 > count_1)
					return ptr[0];

			}
			else if (recorder[i] == '}') // If Right Bracket
			{
				int count_0 = left_bracket_curly;
				int count_1 = right_bracket_curly;

				for (int j = 0; j <= i; j++)
				{
					if (recorder[j] == '{')
						count_0 += 1;

					else if (recorder[j] == '}')
						count_1 += 1;
				}
				right_bracket_curly += 1;
				
				if (count_0 < count_1)
					return i;
			}
			else if (recorder[i] == '{') // If Left Bracket
			{

				int count_0 = left_bracket_curly;
				int count_1 = right_bracket_curly;

				for (int j = i; j < counter; j++)
				{
					if (recorder[j] == '{')
					{
						count_0 += 1;
						ptr[ultimate] = j;
						ultimate++;
					}
					else if (recorder[j] == '}')
					{
						count_1 += 1;
						ultimate--;
					}
				}

				left_bracket_curly += 1;

				if (count_0 > count_1)
					return ptr[0];

			}
		}
	}
	return -1; // If No Error
}
