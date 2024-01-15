#pragma once
#include <random>
#include <time.h>

class MemoryGame
{
private:
	int field_size; // ������ ���� (4, 5, 6)
	int square_size; // ������ ��������
	int size; // ���������� ��������� (16, 25, 36)

public:
	bool* squares; // ��������
	int timer; // ������
	int number_of_squares; // ���������� ����������� ���������
	int number_of_selected_squares; // ���������� ��������� ���������
	bool without_mistakes; // ������� ������� ��� ������ ��� � ��������
	bool game_started; // ���� �������� ��� ���
	bool game_over; // ���� ��������� ��� ���
	int scores; // ����
	int max_scores; // �������� �����

	// �����������
	MemoryGame()
	{
		max_scores = 0;
	}

	// ����������
	~MemoryGame()
	{
		if (squares)
		{
			delete[] squares;
		}
	}

	// ������ ��� field_size
	void SetFieldSize(int field_size)
	{
		this->field_size = field_size;
		square_size = 480 / field_size;
		size = field_size * field_size;
	}

	// ������ ��� field_size
	int GetFieldSize()
	{
		return field_size;
	}

	// ������ ��� square_size
	int GetSquareSize()
	{
		return square_size;
	}

	// ������ ��� size
	int GetSize()
	{
		return size;
	}

	// �������, ������� ������ ����
	void CreateGame()
	{
		timer = 60;
		game_over = false;
		number_of_squares = 2;
		without_mistakes = true;
		scores = 0;

		if (squares)
		{
			delete[] squares;
		}

		squares = new bool[size];
	}

	// �������, ������� ������ ����� �������
	void NewGame()
	{	
		srand(time(NULL));
		game_started = false;
		number_of_selected_squares = 0;

		for (int i = 0; i < size; i++)
		{
			squares[i] = false;
		}

		if (without_mistakes)
		{
			number_of_squares++;
		}

		else if (number_of_squares > 3)
		{
			number_of_squares--;
		}

		for (size_t i = 0; i < number_of_squares; i++)
		{
			int j = rand() % size; // ������

			if (!squares[j])
			{
				squares[j] = true;
			}

			else
			{
				while (squares[j] != false)
				{
					j = rand() % size;
				}

				squares[j] = true;
			}
		}	
	}
};
