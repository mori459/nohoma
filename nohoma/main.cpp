#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

class Teapot {
public:

	Teapot() = default;

	Teapot(double volume, std::string color):
		volume_(volume),
		color_(color)
	{}

	double GetVolume() { return volume_; }
	void SetVolume(double newVolume) {
		volume_ = newVolume;
	}

	std::string GetColor() { return color_; }
	void SetColor(std::string newColor) {
		color_ = newColor;
	}

private:
	double volume_;
	std::string color_;
};

class TeapotCollection {
public:

	void CreateNewTeapot() {

		double volumeInput;
		std::string colorInput;

		std::cout << "������� �����: ";
		std::cin >> volumeInput;

		std::cout << "������� ����: ";
		std::cin.ignore(32000, '\n');
		std::getline(std::cin, colorInput);
		
		AddTeapot(Teapot(volumeInput, colorInput));

	}

	void AddTeapot(Teapot newPot) {
		tparr_.emplace_back(newPot);
	}

	void ShowTeapot() {
		int index;

		do
		{
			std::cout << "�������� ������ �� id (" << tparr_.size() << "): ";
			std::cin >> index;
		} while (index < 1 || index > tparr_.size());
		index--;

		std::cout << "�����\t\t����\n";
		std::cout << tparr_[index].GetVolume() << "\t\t" << tparr_[index].GetColor() << "\n";
		system("pause");
	}

	void ShowCollection() {
		std::cout << "�����\t\t����\n";
		for (size_t i = 0; i < tparr_.size(); i++)
		{
			std::cout << tparr_[i].GetVolume() << "\t\t" << tparr_[i].GetColor() << "\n";
		}
		system("pause");
	}
private:
	std::vector<Teapot> tparr_;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char basicInput;
	bool to_exit = false;

	TeapotCollection mainCollection;
	mainCollection.AddTeapot(Teapot(2.4, "dfds"));

	do
	{
		do
		{
			system("cls");
			std::cout << "\t����\n";
			std::cout << "1) ������� ������\n2) �������� ������\n3) �������� ���������\n4) �����\n";
			std::cin >> basicInput;
		} while (basicInput < '1' || basicInput > '4');

		if (basicInput == '1')
		{
			system("cls");
			std::cout << "\t�������� �������\n";
			mainCollection.CreateNewTeapot();
		}
		else if (basicInput == '2')
		{
			system("cls");
			std::cout << "\t����� �������\n";
			mainCollection.ShowTeapot();
		}
		else if (basicInput == '3')
		{
			system("cls");
			std::cout << "\t���������\n";
			mainCollection.ShowCollection();
		}
		else if (basicInput == '4')
		{
			to_exit = true;
		}
		else
		{
			throw std::invalid_argument("Input invalid: out of scope\n");
		}

	} while (!to_exit);


	return 0;
}