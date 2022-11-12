#include <iostream>
#include <string.h>
#include <time.h>
#include <iomanip>
using namespace std;
//FIFO
class Queue
{
	int* Wait;
	int MaxQueueLength, QueueLength;
public:
	Queue(int m);
	~Queue();
	void Add(int c), Clear(), Show();
	int Extract();
	bool IsEmpty(), IsFull();
	int GetCount();
};
void Queue::Show()
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < QueueLength; i++) cout << Wait[i] << " ";
	cout << "\n-----------------------------------\n";
}
Queue::~Queue()
{
	delete[]Wait;
}
Queue::Queue(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	QueueLength = 0;//длина очереди
}
void Queue::Clear()
{
	QueueLength = 0;//длина очереди
}
bool Queue::IsEmpty()
{
	return QueueLength == 0;//длина очереди
}
bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::GetCount()
{
	return QueueLength;
}
void Queue::Add(int c)
{
	if (!IsFull()) Wait[QueueLength++] = c;
}
int Queue::Extract()
{
	if (!IsEmpty())
	{
		for (int i = 1; i < QueueLength; i++)
		{
			Wait[i - 1] = Wait[i];
			Wait[QueueLength] = Wait[0];
		}
		return 1;
	}
	else return 0;
}
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int size_1 = 10, size_2 = 2, size_3 = 3, size_4 = 5;
	//Queue QU(25);
	//for (int i = 0; i < 5; i++) QU.Add(rand() % 50);
	//QU.Show();
	//for (int i = 0; i < 5; i++)
	//{
	//	QU.Extract();
	//	QU.Show();
	//}
	string* students = new string[size_1];
	students[0] = "иванов";
	students[1] = "смирнов";
	students[2] = "кузнецов";
	students[3] = "попов";
	students[4] = "васильев";
	students[5] = "петров";
	students[6] = "соколов";
	students[7] = "михайлов";
	students[8] = "новиков";
	students[9] = "фёдоров";
	string* groups = new string[size_2];
	groups[0] = students[0], students[1], students[2], students[3], students[4];
	groups[1] = students[5], students[6], students[7], students[8], students[9];
	string* exams = new string[size_3];
	exams[0] = "первый экзамен";
	exams[1] = "второй экзамен";
	exams[2] = "третий экзамен";
	int* marks_1 = new int[size_4];
	int* marks_2 = new int[size_4];
	int* marks_3 = new int[size_4];
	int c = 0;//первый студент
	cout << "выводятся результаты только тех студентов, которые сдали экзамены" << endl;
	cout << setw(6) << exams[0] << setw(6) << exams[1] << setw(6) << exams[2] << endl;
	while (c < size_1)
	{
		cout << students[c] << setw(6);
		int y = 0, z = 0;//первая группа и её первый студент
		while (y < size_2)
		{
			groups[y][z];
			while (z < size_4)
			{
				marks_1[z] = rand() % 12;
				marks_2[z] = rand() % 12;
				marks_3[z] = rand() % 12;
				if (marks_1[z] < 7) marks_2[z] = 0;//провал второго экзамена
				if (marks_2[z] < 7) marks_3[z] = 0;//провал третьего экзамена
				if (marks_3[z] < 7) marks_1[z] = 0;//провал первого экзамена
				else cout << marks_1[z] << setw(6) << marks_2[z] << setw(6) << marks_3[z] << endl;
				z++;
			}
			y++;
		}
		c++;
		cout << endl;
	}
}